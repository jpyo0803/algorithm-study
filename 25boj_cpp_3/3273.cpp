// 두 수의 합
// https://www.acmicpc.net/problem/3273

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool exist[1000005];
int n, x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    exist[v[i]] = true;
  }

  cin >> x;
  int ans = 0;
  for (auto e : v) {
    if (x <= e) continue;
    int d = x - e;
    if (d >= 1 && d <= 1e6 && exist[d]) ans++;
  }
  cout << ans / 2 << "\n";

  return 0;
}