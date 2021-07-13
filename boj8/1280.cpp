// 나무 심기
// https://www.acmicpc.net/problem/1280

#include <stdio.h>

#include <utility>

using namespace std;

constexpr long long kMod = 1000000007;

int N, x;

pair<long long, int> segment_tree[200000 * 4];

pair<long long, int> Query(int n, int nl, int nr, int s, int e) {
  if (nr < s || e < nl) return make_pair(0, 0);
  if (s <= nl && nr <= e) return segment_tree[n];

  int m = (nl + nr) / 2;
  auto lq = Query(2 * n, nl, m, s, e);
  auto rq = Query(2 * n + 1, m + 1, nr, s, e);
  return make_pair(lq.first + rq.first, lq.second + rq.second);
}

pair<long long, int> Update(int n, int nl, int nr, int ind) {
  if (nr < ind || ind < nl) return segment_tree[n];
  if (nl == nr) {
    segment_tree[n].first += ind;
    segment_tree[n].second += 1;
    return segment_tree[n];
  }

  int m = (nl + nr) / 2;
  auto lu = Update(2 * n, nl, m, ind);
  auto ru = Update(2 * n + 1, m + 1, nr, ind);
  segment_tree[n].first = lu.first + ru.first;
  segment_tree[n].second = lu.second + ru.second;
  return segment_tree[n];
}

int main() {
  scanf("%d", &N);

  long long ans = 1;
  for (int n = 0; n < N; ++n) {
    scanf("%d", &x);
    auto lq = Query(1, 0, 200000, 0, x - 1);
    auto rq = Query(1, 0, 200000, x + 1, 200000);
    Update(1, 0, 200000, x);
    long long dist = static_cast<long long>(lq.second) * x - lq.first;
    dist += rq.first - static_cast<long long>(rq.second) * x;
    if (n > 0) {
      ans = ((ans % kMod) * (dist % kMod)) % kMod;
    }
  }

  printf("%lld\n", ans);

  return 0;
}