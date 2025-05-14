// 행성 터널 
// https://www.acmicpc.net/problem/2887

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int x, y, z, tag;
  Info() = default;
};

int n;
int p[100005];

int UF(int x) {
  if (p[x] == x) return x;
  return p[x] = UF(p[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<Info> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y >> v[i].z;
    v[i].tag = i;
    p[i] = i;
  }

  vector<tuple<int, int, int>> edges;

  sort(v.begin(), v.end(), [](const Info& a, const Info& b) {
    return a.x < b.x;
  });
  for (int i = 0; i < n - 1; ++i) {
    edges.emplace_back(v[i + 1].x - v[i].x, v[i].tag, v[i + 1].tag);
  }
  
  sort(v.begin(), v.end(), [](const Info& a, const Info& b) {
    return a.y < b.y;
  });
  for (int i = 0; i < n - 1; ++i) {
    edges.emplace_back(v[i + 1].y - v[i].y, v[i].tag, v[i + 1].tag);
  }
  
  sort(v.begin(), v.end(), [](const Info& a, const Info& b) {
    return a.z < b.z;
  });
  for (int i = 0; i < n - 1; ++i) {
    edges.emplace_back(v[i + 1].z - v[i].z, v[i].tag, v[i + 1].tag);
  }

  sort(edges.begin(), edges.end());

  int ans = 0;
  for (const auto& edge : edges) {
    int ra = UF(get<1>(edge));
    int rb = UF(get<2>(edge));
    if (ra != rb) {
      p[rb] = ra;
      ans += get<0>(edge);
    }
  }

  cout << ans << "\n";

  return 0;
}