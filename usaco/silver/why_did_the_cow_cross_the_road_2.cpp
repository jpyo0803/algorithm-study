// Why Did the Cow Cross the Road II (Silver)
// https://www.acmicpc.net/problem/14465

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k, b;
bool broken[100005];
int ps[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k >> b;
  for (int i = 0; i < b; ++i) {
    int x;
    cin >> x;
    broken[x] = true;
  }

  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    ps[i] = ps[i - 1] + broken[i];
    if (i - k >= 0) ans = min(ans, ps[i] - ps[i - k]);
  }
  cout << ans << "\n";

  return 0;
}