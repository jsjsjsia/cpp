#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("SCORES.INP", "r", stdin);
    freopen("SCORES.OUT", "w", stdout);
    int n;
    cin>> n;

    int scores[i];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    int d = 0;
    for (int i = 1; i < n; i++) {
        int c = scores[i] - scores[i - 1];
        d = max(d,c);
    }

    cout << d << endl;

    return 0;
}
