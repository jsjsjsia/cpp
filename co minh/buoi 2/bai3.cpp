#include <iostream>
using namespace std;
int x[11], d[11], a[11], n, k;

void init ()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void output()
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[x[i]] << " ";
    }
    cout << endl;
}

void tim(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (d[j] == 0)
        {
            x[i] = j;
            d[j] = 1;
            if (i == k)
            {
                output();
            }
            else tim(i + 1);
            d[j] = 0;
        }
    }
}

int main()
{
    freopen("so.inp", "r", stdin);
    freopen("so.out", "w", stdout);
    init();
    tim(1);
}
