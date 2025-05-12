// 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197

#include <bits/stdc++.h>

using namespace std;

int v, e;
int p[10005];

struct Info {
  int a, b, c;
  Info(int _a, int _b, int _c) : a(_a), b(_b), c(_c){};
};

int UF(int x) {
  if (p[x] == x) return x;
  return p[x] = UF(p[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> v >> e;

  for (int i = 1; i <= v; ++i) {
    p[i] = i;
  }

  vector<Info> v;
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v.emplace_back(a, b, c);
  }

  sort(v.begin(), v.end(),
       [](const Info& x, const Info& y) { return x.c < y.c; });

  int ans = 0;
  for (const auto& x : v) {
    int ra = UF(x.a);
    int rb = UF(x.b);

    if (ra != rb) {
      p[rb] = ra;
      ans += x.c;
    }
  }

  cout << ans << "\n";

  return 0;
}