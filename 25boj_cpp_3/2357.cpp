// 최솟값과 최댓값
// https://www.acmicpc.net/problem/2357

#include <bits/stdc++.h>

using namespace std;

int n, m;

pair<int, int> tree[200005]; // min, max

pair<int, int> Query(int a, int b) {
  a += n, b += n;

  int mi = 1e9, ma = 1;
  while (a <= b) {
    if (a % 2 == 1) {
      mi = min(mi, tree[a].first);
      ma = max(ma, tree[a].second);
      a++;
    }
    if (b % 2 == 0) {
      mi = min(mi, tree[b].first);
      ma = max(ma, tree[b].second);
      b--;
    }
    a /= 2, b /= 2;
  }
  return {mi, ma};
}

void Update(int x, int v) {
  x += n;
  tree[x].first = tree[x].second = v;
  for (x /= 2; x >= 1; x /= 2) {
    tree[x].first = min(tree[x * 2].first, tree[x * 2 + 1].first);
    tree[x].second = max(tree[x * 2].second, tree[x * 2 + 1].second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i < 2 * n; ++i) {
    tree[i].first = 1e9;
    tree[i].second = 1;
  }

  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    Update(i, v);
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    auto res = Query(a, b);
    cout << res.first << " " << res.second << "\n";
  }

  return 0;
}