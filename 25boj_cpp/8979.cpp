// 올림픽
// https://www.acmicpc.net/problem/8979

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int g, s, b;

  Info() = default;

  Info(int g, int s, int b) : g(g), s(s), b(b) {}
};

bool compare(const Info& x, const Info& y) {
  if (x.g == y.g) {
    if (x.s == y.s) {
      return x.b < y.b;
    } else {
      return x.s < y.s;
    }
  } else {
    return x.g < y.g;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<Info> v;

  Info target;

  for (int i = 0; i < n; ++i) {
    int id, g, s, b;
    cin >> id >> g >> s >> b;

    v.emplace_back(g, s, b);

    if (id == k) {
      target = v.back();
    }
  }

  sort(v.begin(), v.end(), compare);

  auto it = upper_bound(v.begin(), v.end(), target, compare);

  cout << distance(it, v.end()) + 1 << "\n";

  return 0;
}