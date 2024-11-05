#include <iostream>
using namespace std;
int prime[10000000];
int l, r;
void sieve() {
  for (int i = 0; i < 10000000; i++) {
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i < 10000000; i++) {
    if (prime[i]) {
      for (int j = i * i; j < 10000000; j += i) {
        prime[j] = 0;
      }
    }
  }
}
int sum(int n) {
  int s = 0;
  while (n > 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}
int main() {
  sieve();
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    if (prime[i] && prime[sum(i)]) {
      cout << i << " ";
    }
  }
  return 0;
}
