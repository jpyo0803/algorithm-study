// 선 긋기
// https://www.acmicpc.net/problem/2170

#include <stdio.h>

#include <algorithm>
#include <utility>

using namespace std;

int N, X, Y;
pair<int, int> pairs[1000001];

bool Comparator(const pair<int, int>& x, const pair<int, int>& y) {
  return x.first < y.first;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &X, &Y);
    pairs[i].first = X;
    pairs[i].second = Y;
  }

  sort(pairs, pairs + N, Comparator);
  pairs[N].first = 1000000001;
  pairs[N].second = 1000000001;

  int ans = 0;

  pair<int, int> prev = make_pair(-1000000001, -1000000001);
  for (int i = 0; i <= N; i++) {
    auto& p = pairs[i];
    if (prev.second < p.first) {
      ans += prev.second - prev.first;
      prev = p;
    } else {
      prev.second = prev.second < p.second ? p.second : prev.second;
    }
  }

  printf("%d\n", ans);
  return 0;
}