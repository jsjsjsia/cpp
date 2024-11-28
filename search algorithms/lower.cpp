#include <iostream>
using namespace std;

int lower(int a[], int n, int x){
    int res = -1, left = 0, right = n - 1;
    while(left <= right){
       int mid = (left + right) / 2;
       if(a[mid] >= x){
           res = mid;
           right = mid - 1;
       }
       else{
           left = mid + 1;
       }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << lower(a, n, x);
}
