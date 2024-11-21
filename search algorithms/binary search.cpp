#include <iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    bool ans = binarySearch(arr, n, key);
    if (ans)
    {
        cout << "Found at index: " << ans << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}
