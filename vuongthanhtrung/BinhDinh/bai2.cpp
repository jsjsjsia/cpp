#include <iostream>
using namespace std;

int main()
{
    //freopen ("test/test03/dientich.inp", "r", stdin);
    //freopen ("so.out", "w", stdout);
    int x,R;
    cin >> R;
    int smax = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        smax = max(smax, 4 * (int)(sqrt(R*R - i*i) * i));
    }
    cout << smax;
    return 0;
}
