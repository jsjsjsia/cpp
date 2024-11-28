#include <iostream>
using namespace std;
int x[11], n, k, a[11];

void init(){
    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void output(){
    for (int i = 0; i < n; i++)
    {
        cout << a[x[i]] << " ";
    }
    cout << endl;
}

void tim(int i){
    for(int j = 1; j <= n; j++)
    {
        x[i] = j;
        if (i == k){
            output();
        }
        else tim(i + 1);
    }
}

int main(){
    init();
    tim(1);
    return 0;
}
