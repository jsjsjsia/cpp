#include <climits>
#include <cstdio>
#include <iostream>
#define N 1000002
using namespace std;

int a[N];

int main()
{
    freopen("so.inp", "r", stdin);
    freopen("so.out", "w", stdout);
    int lmax = INT_MIN;
    int d, c;
    // int n = 10e6 + 1;
    int n;
    cin >> n;
    // int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum > 0)
            {
                int l;
                l = j - i + 1;
                if (l >= lmax)
                {
                    l = lmax;
                    d = i;
                    c = j;
                }
            }
        }
    }
    cout << d << " " << c;
}
