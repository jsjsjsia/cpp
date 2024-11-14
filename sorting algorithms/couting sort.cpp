#include <iostream>
using namespace std;

int dem[1000001];
void coutingSort(int arr[], int n)
{
    int K = -1e9;
    for (int i = 0; i < n; i++)
    {
        dem[arr[i]]++;
        K = max(K, arr[i]);
    }
    for (int i = 0; i <= K; i++)
    {
        if(dem[i])
        {
            for (int j = 0; j < dem[i]; j++)
            {
                cout << i<< " ";
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    coutingSort(arr, n);
    return 0;
}
