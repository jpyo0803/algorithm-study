// C - Equilateral Triangle (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_c

#include <bits/stdc++.h>

using namespace std;

int n, l;
int cnt[300005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l;
  if (l % 3 != 0) {
    cout << "0\n";
    return 0;
  }

  int x = 0;
  cnt[x]++;
  for (int i = 0; i < n - 1; ++i) {
    int d;
    cin >> d;
    x = (x + d) % l;
    cnt[x]++;
  }

  long long ans = 0;

  int ldiv3 = l / 3;
  for (int i = 0; i < ldiv3; ++i) {
    ans += (long long)cnt[i] * cnt[i + ldiv3] * cnt[i + ldiv3 + ldiv3];
  }

  cout << ans << "\n";

  return 0;
}