#include<bits/stdc++.h>
using namespace std;

string hnp(int n) {
    string np = "";
    while (n > 0) {
        np = to_string(n % 2) + np;
        n /= 2;
    }
    return np;
}

int main() {
    ifstream inputFile("DIGITAL.INP");
    ofstream outputFile("DIGITAL.OUT");

    int n;
    inputFile >> n;

    string np = hnp(n);
    outputFile << np <<endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
