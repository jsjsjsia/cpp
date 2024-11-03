#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    freopen("CDIV.INP", "r", stdin);
    freopen("CDIV.OUT", "w", stdout);
    int n, kq, a; cin>>n;
    int x; cin>> x;
    for(int i=0; i<= n; i++)
    {
       cin>> a;
       kq = gcd(x,a);
    }
    cout << kq;
}
