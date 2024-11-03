#define N 100
#include <iostream>
using namespace std;
int c[N+1];
int sumDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    freopen ("so.inp", "r", stdin);
    freopen("so.out", "w", stdout);
    int l,r,ans = 0;
    cin >> l >> r;
    for (int x = l; x <= r; x++)
    {
        int k = sumDigit(x);
        if (c[k] == 0)
        {
            c[k] = x;
        }
        else
        {
            ans = max(ans, x- c[k]);
        }
    }
   cout<< ans;
   return 0;


}
