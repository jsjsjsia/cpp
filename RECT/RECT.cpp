#include<bits/stdc++.h>
using namespace std;


int main() {
    ifstream inputFile("RECT.INP");
    ofstream outputFile("RECT.OUT");

    int x1, y1, x2, y2, x3, y3, x4, y4;
    inputFile >> x1 >> y1 >> x2 >> y2;
    inputFile >> x3 >> y3 >> x4 >> y4;

    int A = abs(x1 - x2) * abs(y1 - y2);
    int B = abs(x3 - x4) * abs(y3 - y4);

    int smax = A > B ? A : B;

    outputFile << smax;

    inputFile.close();
    outputFile.close();

    return 0;
}
