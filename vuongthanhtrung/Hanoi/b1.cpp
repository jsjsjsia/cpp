#include <iostream>
using namespace std;

int main()
{
   float s1, s2, v1, v2, t;
   cin>> s1 >> v1 >> s2 >> v2;
   t = (s2 - s1) / (v1 - v2);
   cout << t;
}
