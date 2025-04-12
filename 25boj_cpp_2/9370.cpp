// 미확인 도착지 
// https://www.acmicpc.net/problem/9370

#include <bits/stdc++.h>

using namespace std;

int T, n, m, t, s, g, h;
int gh_cost;

vector<pair<int, int>> adj_list[2010];
int ts[105];

vector<int> Solve2(int s, bool disable) {
  vector<int> dist(n + 10, 1e9);

  priority_queue<pair<int, int>> pq; // -cost, u
  pq.emplace(0, s);

  bool first = true;
  while (pq.empty() == false) {
    auto e = pq.top();
    pq.pop();

    int cost = -e.first;
    int u = e.second;

    if (first) {
      dist[u] = cost;
      first = false;
    } 

    for (auto x : adj_list[u]) {
      int v = x.first;
      if (disable) {
        if ((u == g && v == h) || (v == g && u == h)) continue;
      }
      int next_cost = cost + x.second;
      if (dist[v] > next_cost) {
        dist[v] = next_cost;
        pq.emplace(-next_cost, v);
      }
    }
  }
  return dist;  
} 

vector<int> Solve(int g, int h) {
  auto dist1 = Solve2(s, true);
  auto dist2 = Solve2(s, false);
  auto dist3 = Solve2(h, false);
  
  vector<int> cands;
  for (int i = 0; i < t; ++i) {
    int target = ts[i];
    int dist_sum = dist2[g] + gh_cost + dist3[target];
    // dist1[target] vs dist_sum
    // there is a faster way to 'target' but you took gh, that means you are not going to 'target'
    if (dist1[target] < dist_sum) continue; 
    cands.push_back(target);
  }
  return cands;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> n >> m >> t;
    cin >> s >> g >> h;

    for (int i = 1; i <= n; ++i) adj_list[i].clear();

    for (int i = 0; i < m; ++i) {
      int a, b, d;
      cin >> a >> b >> d;
      adj_list[a].emplace_back(b, d);
      adj_list[b].emplace_back(a, d);
      if ((a == g && b == h) || (b == g && a == h)) {
        gh_cost = d;
      } 
    }

    for (int i = 0; i < t; ++i) cin >> ts[i];

    auto res1 = Solve(g, h);
    auto res2 = Solve(h, g);
    vector<bool> chk(n + 10, false);
    for (auto e : res1) chk[e] = true;
    for (auto e : res2) {
      if (chk[e] == false) res1.push_back(e);
    }
    sort(res1.begin(), res1.end());
    for (auto e : res1) {
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}