#include <iostream>
using namespace std;
int main(){
    long long x, y, ans;
    cin >> x >> y;
    ans = (x / 2) * y;
    if(x % 2 == 1)
    {
        ans += y;
    }
    cout << ans;
}
