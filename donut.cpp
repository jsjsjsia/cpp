// compile in shell with $ g++ donut.cpp -o donut
// execute in shell with $ ./donut

// code based on andy sloane's donut.c tutorial available at
// https://www.a1k0n.net/2011/07/20/donut-math.html


#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <chrono>

using namespace std::chrono;

const int frame_time = 40000; // time in microseconds per frame
const int screen_width = 80; // determine in shell with $ tput cols
const int screen_height = 24; // determine in shell with $ tput lines

const float pi = M_PI;
const float theta_spacing = 0.07;
const float phi_spacing = 0.02;

const float R1 = 1; // donut thickness radius
const float R2 = 2; // donut radius
const float K2 = 5; // distance from donut to camera

// calculate K1 based on screen size
// maximum x-distance occurs roughly at the edge of the torus (x = R1 + R2, z = 0)
// we want that to be displaced over half of the width of the screen,
// which is 1/4th of the way from the center to the side of the screen
// screen_width * 1/4 = K1 * x / (K2 + z) = K1 * (R1 + R2) / (K2 + 0)
const float K1 = screen_width * 1/4 * K2 / (R1 + R2); // focal lenght z' in x-direction
const float ratio = 0.5; // focal length ratio (x-direction by y-direction)


// frame rendering function
void render_frame(float A, float B) {
  // precompute sines and cosines of A and B
  float cosA = cos(A), sinA = sin(A);
  float cosB = cos(B), sinB = sin(B);

  char output[screen_width * screen_height];
  memset(output, ' ', screen_width * screen_height); // set all elements of output to ' '

  float zbuffer[screen_width * screen_height];
  memset(zbuffer, 0, screen_width * screen_height * 4); // 4 bytes per float

  // theta goes around the cross-sectional circle of a torus
  for(float theta = 0; theta < 2 * pi; theta += theta_spacing) {
    // precompute sines and cosines of theta
    float costheta = cos(theta), sintheta = sin(theta);

    // phi goes around the center of revolution of a torus
    for(float phi = 0; phi < 2 * pi; phi += phi_spacing) {
      // precompute sines and cosines of phi
      float cosphi = cos(phi), sinphi = sin(phi);

      // x, y coordinates of the circle, before revolving
      float circlex = R2 + R1 * costheta;
      float circley = R1 * sintheta;

      // final 3D (x, y, z) coordinate after rotations
      float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;
      float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;
      float z = K2 + cosA * circlex * sinphi + circley * sinA;
      float ooz = 1 / z; // one over z

      // x and y projections; note that y is negated here because y goes up in 3D space but down in 2D space
      int xp = (int) (screen_width / 2 + K1 * x * ooz); // x projection + width center
      int yp = (int) (screen_height / 2 - K1*ratio * y * ooz); // y projection + height center

      // calculate luminance
      float L = cosphi * costheta * sinB - cosA * costheta * sinphi
              - sinA * sintheta
              + cosB * (cosA * sintheta - costheta * sinA * sinphi);

      // L ranges from -sqrt(2) to +sqrt(2)
      // if L < 0, surface is pointing away from us, don't plot
      if(L > 0 && xp > 0 && xp < screen_width && yp > 0 && yp < screen_height) {
        // test against the z-buffer : larger 1/z means the pixel is closer to
        // the viewer than what's already plotted
        if(ooz > zbuffer[xp + screen_width * yp]) {
          zbuffer[xp + screen_width * yp] = ooz;

          // luminance_index is now in the range 0 to 11 (8 * sqrt(2) = 11.3)
          int luminance_index = L * 8;

          // lookup the character corresponding to the luminance and plot it to our output
          output[xp + screen_width * yp] = ".,-~:;=!*#$@"[luminance_index];
        }
      }

    }
  }

  // dump output to the screen
  printf("\x1b[H"); // return cursor to home position

  for(int j = 0; j < screen_height; j++) {
    for(int i = 0; i < screen_width; i++)
      putchar(output[i + screen_width * j]);
    putchar('\n');
  }

}


int main() {
  printf("\x1b[2J"); // clear screen and set cursor to home

  float A = 0;
  float B = 0;

  // never ending rendering loop
  for( ; ; ) {
    steady_clock::time_point start = high_resolution_clock::now(); // start timer
    render_frame(A, B);
    steady_clock::time_point end = high_resolution_clock::now(); // end timer

    // measured time for computing one frame
    microseconds time = duration_cast<microseconds>(end - start);

    float diff = frame_time - time.count(); // we want at least frame_time µs between each frame
    diff *= (diff > 0); // only sleep difference to frame_time µs if > 0, otherwise no sleep
    usleep(diff);

    A += 0.04; // increment in rotation around x-axis
    B += 0.02; // increment in rotation around z-axis
  }

  return 0;
}
