#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,k,s=0;
    cin >> n;
    for (int i=1; i <= sqrt(n); i++){
        k = n/i;
        if (n!=k && n%i==0 && k/2==0 ) s ++;
    }
    cout << s +2;
}
