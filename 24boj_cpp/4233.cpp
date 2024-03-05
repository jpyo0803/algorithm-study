// 가짜소수
// https://www.acmicpc.net/problem/4233

#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int x) {
  bool ok = true;
  for (int i = 2; i <= (int)sqrt(x); ++i) {
    if (x % i == 0) {
      ok = false;
      break;
    }
  }
  return ok;
}

long long Pow(long long a, long long p, long long orig_p) {
  if (p == 0) return 1;
  auto ret = Pow(a, p / 2, orig_p) % orig_p;
  ret *= ret;
  ret %= orig_p;
  if (p % 2) ret *= a;
  return ret % orig_p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    int p, a;
    cin >> p >> a;
    if (p == 0 && a == 0) break;

    bool is_p = IsPrime(p);
    int pow_res = Pow(a, p, p);
    bool is_fake = false;
    if (is_p == false && pow_res == a) {
      is_fake = true;
    }
    cout << (is_fake ? "yes" : "no") << "\n";
  }

  return 0;
}