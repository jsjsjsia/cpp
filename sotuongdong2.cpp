#include <iostream>
using namespace std;
//int c[N+1];
int sumDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int a[100];
    int l,r;
    int ans = 0;
    cin >> l >> r;
    for(int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            //cout << sumDigit(i) << " " << sumDigit(j) << endl;
            if (sumDigit(i) == sumDigit(j)) {
                ans = max(ans, (j - i));
                cout<< i << " " << j << " "<< ans << endl;
            }


            /*int k = sumDigit(x);
            if (c[k] == 0)
            {
                c[k] = x;
            }
            else
            {
                ans = max(ans, x- c[k]);
                }*/
        }
    }
}
