#include <iostream>
using namespace std;

int upper(int a[], int n, int x){
    int res = -1, left = 0, right = n - 1;
    while(left <= right){
       int mid = (left + right) / 2;
       if(a[mid] <= x){
           res = mid;
           left = mid + 1;
       }
       else{
           right = mid - 1;
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
    cout << upper(a, n, x);
}
