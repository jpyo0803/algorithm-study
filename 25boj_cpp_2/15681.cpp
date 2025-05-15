// 트리와 쿼리
// https://www.acmicpc.net/problem/15681

#include <bits/stdc++.h>

using namespace std;

int n, r, q;

vector<int> adj_list[100005];
int ans[100005];

int Traverse(int x, int prev) {
  int cnt = 1;
  for (auto y : adj_list[x]) {
    if (y == prev) continue;
    cnt += Traverse(y, x);
  }
  ans[x] = cnt;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> r >> q;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  Traverse(r, -1);

  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << "\n";
  }

  return 0;
}