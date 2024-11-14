#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int pos = i - 1, x = a[i];
        cout << x << endl;
        while(pos >= 0 && a[pos] > x){
            a[pos + 1] = a[pos];
            --pos;
            // cout << pos << " " << x << " " << a[pos + 1] << " " << a [pos] << endl;
        }
        a[pos + 1] = x;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
