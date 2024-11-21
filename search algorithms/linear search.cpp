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
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

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
