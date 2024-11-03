#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream infile("DIFFEREN.INP");
    ofstream outfile("DIFFEREN.OUT");

    int n;
    infile >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        infile >> a[i];
    }


    sort(a.begin(), a.end());

    int min = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
        min = min(min, abs(a[i] - a[i - 1]));
    }

    outfile << min << endl;

    infile.close();
    outfile.close();

    return 0;
}
