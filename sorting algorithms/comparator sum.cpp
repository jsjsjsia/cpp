#include <iostream>
using namespace std;

int sum(int n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool cmp(int a, int b)
{
    return sum(a) < sum(b);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
