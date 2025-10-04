// Greg and Array
// https://codeforces.com/contest/295/problem/A

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, k;
int arr[100005];
ll ans[100005];
int qps[100005];
tuple<int, int, int> op[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= m; ++i) {
    int l, r, d;
    cin >> l >> r >> d;
    op[i] = {l, r, d};
  }

  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    qps[x]++, qps[y + 1]--;
  }
  for (int i = 1; i <= m; ++i) qps[i] += qps[i - 1];

  for (int i = 1; i <= m; ++i) {
    int l, r, d;
    tie(l, r, d) = op[i];
    ans[l] += (ll)d * qps[i]; 
    ans[r + 1] -= (ll)d * qps[i]; 
  }

  for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1];
  for (int i = 1; i <= n; ++i) ans[i] += arr[i];

  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}