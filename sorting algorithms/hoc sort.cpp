#include <iostream>
using namespace std;

int main(){
    int a[5] = {6, 7, 2, 0, 5};
    int n = 5;
    cout << a << endl;
    cout << a + n << endl;
    cout << &a[0] << endl;
    sort (a, a + n);
    cout << sort (a, a + n, greater<int>());
    // sort (a + x, a + y + 1);
    // sort (a + x, a + y + 1, greater<int>());
    // sort (v.begin(), v.end());
    // sort (v.begin(), v.end(), greater<int>());
    // sort (v.begin() + x, v.end() + y);
    // sort (v.begin() + x, v.end() + y, greater<int>());
}
