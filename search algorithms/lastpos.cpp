#include <iostream>
using namespace std;

int lastpos(int a[], int n, int x){
    int res = -1, left = 0, right = n-1;
     while(left <= right){
        int mid = (left + right) / 2;
        if (a[mid] == x){
           res = mid;
           left = mid + 1;
       }

       else if (a[mid] < x) {
           left = mid + 1;
       }
       else {
           right = mid - 1;
       }
   }
   return res;
}

int main() { int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << x << " " << lastpos(arr, n, x) << endl;
    return 0;
}
