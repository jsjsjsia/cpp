#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    int x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    if (linearSearch(arr, n, x))
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }
    return 0;
}
