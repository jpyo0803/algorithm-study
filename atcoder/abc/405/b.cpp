// B - Not All (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_b

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int m, n;

int cnt[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  bool ok = true;
  for (int i = 1; i <= m; ++i) {
    if (cnt[i] == 0) {
      ok = false;
      break;
    }
  }

  if (ok) {
    int ans = 1;
    while (ans <= n) {
      int x = a.back();
      a.pop_back();

      cnt[x]--;
      if (x >= 1 && x <= m) {
        if (cnt[x] == 0) break;
      }
      ans++;
    }
    cout << ans << "  \n";
  } else {
    cout << "0\n";
  }
  return 0;
}