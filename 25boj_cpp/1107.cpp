// 리모컨
// https://www.acmicpc.net/problem/1107

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> keys;

int ans = 1e9;

void Solve(int depth, int num) {
  if (depth >= 1) {
    ans = min(ans, depth + abs(n - num));
  }

  if (depth == 6) return;
  for (auto key : keys) {
    Solve(depth + 1, num * 10 + key);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  vector<bool> vv(10, true);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    vv[x] = false;
  }

  for (int i = 0; i < 10; ++i) {
    if (vv[i]) keys.push_back(i);
  }

  Solve(0, 0);

  ans = min(ans, abs(n - 100));
  cout << ans << "\n";

  return 0;
}