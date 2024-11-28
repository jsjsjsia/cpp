#include <iostream>
using namespace std;

int main()
{
    int a[7] = {1, 2, 3, 3, 3, 4, 6};
    auto it = lower_bound(a, a + 7, 8);
    if (it == a + 7)
        cout << "not found" << endl;
    else{
        cout << *it << endl;
    }
    cout << it - a << endl;
}
