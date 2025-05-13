// GCD(n, k) = 1
// https://www.acmicpc.net/problem/11689

#include <bits/stdc++.h>

using namespace std;

bool chk[1000010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> pns;

  for (int i = 2; i <= 1000000; i++) {
    if (chk[i]) continue;
    pns.push_back(i);
    for (int j = i; j <= 1000000; j += i) {
      chk[j] = true;
    }
  }

  long long n;
  cin >> n;

  if (n == 1) {
    cout << "1\n";
    return 0;
  }

  // first check whether it is a prime

  bool is_prime = true;
  for (auto pn : pns) {
    if (pn > sqrt(n)) break;
    if (n % pn == 0) {
      is_prime = false;
      break;
    }
  }

  if (is_prime) {
    cout << n - 1 << "\n";
    return 0;
  }

  vector<long long> factors;
  long long n2 = n;
  for (auto pn : pns) {
    if (n2 == 1) break;

    bool first = true;
    while (n2 % pn == 0) {
      if (first) {
        first = false;
        factors.push_back(pn);
      }
      n2 /= pn;
    }
  }

  if (n2 != 1) factors.push_back(n2);

  long long ans = n;
  for (auto factor : factors) {
    ans /= factor;
  }
  for (auto factor : factors) {
    ans *= (factor - 1);
  }

  cout << ans << "\n";

  return 0;
}