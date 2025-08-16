// F - Athletic (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_f

#include <bits/stdc++.h>

using namespace std;

int n, d, r;
int h2i[500005];
int dp[500005];
int tree[1000005];

int Query(int a, int b) {
  a += n, b += n;
  int ma = -1e9;
  while (a <= b) {
    if (a % 2 == 1) ma = max(ma, tree[a++]);
    if (b % 2 == 0) ma = max(ma, tree[b--]);
    a /= 2, b /= 2;
  }
  return ma;
}

void Update(int p, int v) {
  p += n;
  tree[p] = v;
  for (p /= 2; p >= 1; p /= 2) {
    tree[p] = max(tree[2 * p], tree[2 * p + 1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d >> r;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    h2i[h - 1] = i;
  }
  
  for (int i = 1; i < 2 * n; ++i) tree[i] = -1e9;

  for (int h = 0; h < n; ++h) {
    if (h - d >= 0) {
      Update(h2i[h - d], dp[h - d]);
    }
    int res = Query(max(0, h2i[h] - r), min(n - 1, h2i[h] + r));
    dp[h] = res == -1e9 ? 0 : res + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
  cout << ans << "\n";

  return 0;
}