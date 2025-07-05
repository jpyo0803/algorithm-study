// E - LCM Sequence (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_e

#include <bits/stdc++.h>

using namespace std;

long long l, r;
vector<long long> pv;

void Eras() {
  vector<bool> chk(1e7 + 5, false);
  for (long long i = 2; i <= 1e7; ++i) {
    if (chk[i]) continue;
    pv.push_back(i);
    for (long long j = i * i; j <= 1e7; j += i) {
      chk[j] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Eras();

  cin >> l >> r;

  int ans = 0;

  vector<bool> chk(1e7 + 5, false);
  for (auto p : pv) {
    for (long long i = (l / p + 1) * p; i <= r;
         i += p) {  // 'L' must be included to be a part of answer so no check
                    // required
      // if already checked by previous prime, it means 'i' is composite number,
      // so it does not contribute to the answer anyways
      if (chk[i - l]) continue;
      chk[i - l] = true;
      long long j = i;
      while (j % p == 0) j /= p;
      if (j == 1) ans++;
    }
  }

  for (long long i = l; i <= r; ++i) {
    if (chk[i - l] == false)
      ans++;  // if not checked it means it is a prime number, which always
              // contribute to answer, and  // include 'L' as part of answer

  }

  cout << ans << "\n"; 
  return 0;
}