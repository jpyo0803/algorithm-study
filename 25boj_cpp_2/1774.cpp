// 우주신과의 교감
// https://www.acmicpc.net/problem/1774

#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> pos[1005];
int p[1005];

int UF(int x) {
  if (p[x] == x) return x;
  return p[x] = UF(p[x]);
}

long long DistanceSqr(pair<int, int> p1, pair<int, int> p2) {
  long long dx = p2.first - p1.first;
  long long dy = p2.second - p1.second;
  return dx * dx + dy * dy;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    cin >> pos[i].first >> pos[i].second;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    int ra = UF(a);
    int rb = UF(b);
    if (ra != rb) {
      p[rb] = ra;
    }
  }

  vector<pair<long long, pair<int, int>>> edges;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      edges.push_back({DistanceSqr(pos[i], pos[j]), {i, j}});
    }
  }

  sort(edges.begin(), edges.end());

  double ans = 0.0;
  for (const auto& edge : edges) {
    int ra = UF(edge.second.first);
    int rb = UF(edge.second.second);
    if (ra != rb) {
      p[rb] = ra;
      ans += sqrt(edge.first);
    }
  }
  
  cout << fixed << setprecision(2);
  cout << ans << "\n";

  return 0;
}