// 지름길
// https://www.acmicpc.net/problem/1446

#include <bits/stdc++.h>

using namespace std;

int n, d;

struct Info {
  int u, v, dst;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d;

  vector<Info> infos(d + 10); // shortcut
  for (int i = 0; i < n; ++i) {
    cin >> infos[i].u >> infos[i].v >> infos[i].dst;
  }

  vector<map<int, int>> sc(d + 10);
  for (auto info : infos) {
    auto it = sc[info.u].find(info.v);
    if (it == sc[info.u].end()) {
      sc[info.u][info.v] = info.dst;
    } else {
      it->second = min(it->second, info.dst);
    }
  }

  priority_queue<pair<int, int>> pq;
  vector<int> min_dst(d + 10, 1e9);

  pq.emplace(0, 0); // dst, curr vert

  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();
    int total_dst = -x.first;
    int u = x.second;

    if (min_dst[u] <= total_dst) continue;

    min_dst[u] = total_dst;

    if (u + 1 <= d) pq.emplace(-(total_dst + 1), u + 1);
    for (const auto& e : sc[u]) {
      pq.emplace(-(total_dst + e.second), e.first);
    }
  }  

  cout << min_dst[d] << "\n";

  return 0;
}