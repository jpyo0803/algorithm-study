// 별자리 만들기
// https://www.acmicpc.net/problem/4386

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int a, b;
  double dist;

  Info(int _a, int _b, double _dist) : a(_a), b(_b), dist(_dist) {}
};

int n;
int p[105];

double Distance(pair<float, float> a, pair<float, float> b) {
  double dx = a.first - b.first;
  double dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

int UF(int x) {
  if (p[x] == x) return x;
  return p[x] = UF(p[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) p[i] = i;
  vector<pair<float, float>> coord(n);
  for (int i = 0; i < n; ++i) cin >> coord[i].first >> coord[i].second;

  vector<Info> edges;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      edges.emplace_back(i, j, Distance(coord[i], coord[j]));
    }
  }

  sort(edges.begin(), edges.end(),
       [](const Info& x, const Info& y) { return x.dist < y.dist; });

  double ans = 0.0;
  for (const auto& edge : edges) {
    int ra = UF(edge.a);
    int rb = UF(edge.b);
    if (ra != rb) {
      p[rb] = ra;
      ans += edge.dist;
    }
  }

  cout << fixed << setprecision(2);
  cout << ans << "\n";

  return 0;
}