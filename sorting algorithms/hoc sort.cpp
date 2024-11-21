#include <iostream>
using namespace std;

int main(){
    int a[5] = {6, 7, 2, 0, 5};
    int n = 5;
    cout << a << endl;
    cout << a + n << endl;
    cout << &a[0] << endl;
    sort (a, a + n);
    sort (a, a + n, greater<int>());
    cout << a;
}
