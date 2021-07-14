// 북서풍
// https://www.acmicpc.net/problem/5419

#include <stdio.h>

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int T, N, X, Y;

bool Comparator(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

vector<pair<int, int>> islands;
vector<int> islands_y;
unordered_map<int, int> y_map;

long long segment_tree[75000 * 4];

long long Update(int n, int nl, int nr, int ind) {
  if (ind < nl || nr < ind) return segment_tree[n];
  if (nl == nr) return segment_tree[n] += 1;

  int mid = (nl + nr) / 2;
  return segment_tree[n] =
             Update(n * 2, nl, mid, ind) + Update(n * 2 + 1, mid + 1, nr, ind);
}

long long Query(int n, int nl, int nr, int s, int e) {
  if (nr < s || e < nl) return 0;
  if (s <= nl && nr <= e) return segment_tree[n];

  long long mid = (nl + nr) / 2;
  return Query(n * 2, nl, mid, s, e) + Query(n * 2 + 1, mid + 1, nr, s, e);
}

int main() {
  scanf("%d", &T);
  islands.reserve(75000);
  islands_y.reserve(75000);
  for (int t = 0; t < T; ++t) {
    islands.clear();
    islands_y.clear();
    y_map.clear();
    for (int i = 0; i < 75000 * 4; i++) segment_tree[i] = 0;
    scanf("%d", &N);
    for (int n = 0; n < N; ++n) {
      scanf("%d%d", &X, &Y);
      islands.emplace_back(X, Y);
    }
    sort(islands.begin(), islands.end(), Comparator);
    for (auto& island : islands) islands_y.push_back(island.second);

    sort(islands_y.begin(), islands_y.end());
    islands_y.resize(unique(islands_y.begin(), islands_y.end()) -
                     islands_y.begin());
    for (int i = 0; i < islands_y.size(); ++i) y_map[islands_y[i]] = i;

    long long ans = 0;
    for (int n = 0; n < N; ++n) {
      ans += Query(1, 0, islands_y.size(), 0, y_map[islands[n].second]);
      Update(1, 0, islands_y.size(), y_map[islands[n].second]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}