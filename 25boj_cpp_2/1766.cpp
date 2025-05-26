// 문제집
// https://www.acmicpc.net/problem/1766

#include <bits/stdc++.h>

using namespace std;

int n, m;
int in_cnt[32005];
vector<int> adj_list[32005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    in_cnt[b]++;
  }

  priority_queue<int> pq;
  for (int i = 1; i <= n; ++i) {
    if (in_cnt[i] == 0) {
      pq.emplace(-i);
    }
  }

  while (pq.empty() == false) {
    int u = -pq.top();
    pq.pop();

    cout << u << " ";

    for (auto v : adj_list[u]) {
      in_cnt[v]--;
      if (in_cnt[v] == 0) {
        pq.emplace(-v);
      }
    }
  }

  return 0;
}