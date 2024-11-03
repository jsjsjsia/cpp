#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 10000;

int main() {
    freopen ("gift.inp", "r", stdin);
    freopen ("gift.out", "r", stdout);
    int N, K;
    cin >> N >> K;

    int a[MAX_N];
    int dp[MAX_N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    int maxCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && (i - j) >= K) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxCount = max(maxCount, dp[i]);
    }
    cout << maxCount << endl;
    return 0;
}
