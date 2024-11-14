#include <iostream>
using namespace std;

void selection (int a[], int n){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
       int min_pos = i;
       for(int j = i + 1; j < n; j++)
       {
           if(a[j] < a[min_pos])
          {
              min_pos = j;
          }
       }
    }
    swap(a[j], a[min_pos]);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selection(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
}
