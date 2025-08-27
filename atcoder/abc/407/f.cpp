// F - Sums of Sliding Window Maximum (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_f

#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
long long ans[3][200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<pair<long long, int>> vv(n);
  for (int i = 0; i < n; ++i) vv[i] = {a[i], i};
  sort(vv.begin(), vv.end());

  // window that contains indices of larger elements than current one
  set<int> ws = {-1, n};

  for (int i = n - 1; i >= 0; --i) {
    int val, idx;
    tie(val, idx) = vv[i];

    // find closest to my right. all in ws are larger than me
    auto rit = ws.upper_bound(idx);
    auto lit = rit;
    lit--;

    int L = idx - *lit - 1;
    int R = *rit - idx - 1;

    int xmi = min(L, R), xma = max(L, R);

    ans[0][1] += val;
    ans[0][1 + xmi + 1] -= val;
    ans[0][1 + xma + 1] -= val;
    ans[0][1 + xmi + xma + 2] += val;

    ws.insert(idx);
  }
  
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[2][i] << "\n";
  }

  return 0;
}