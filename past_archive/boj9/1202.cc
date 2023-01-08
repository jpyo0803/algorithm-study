// 보석 도둑
// https://www.acmicpc.net/problem/1202

#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int N, K;
multiset<int> bags;
vector<pair<int, int>> items;

bool Comparator(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return lhs.second > rhs.second;
}

int main() {
  scanf("%d%d", &N, &K);
  items.reserve(N);
  for (int n = 0; n < N; ++n) {
    int m, v;
    scanf("%d%d", &m, &v);
    items.emplace_back(m, v);
  }
  sort(items.begin(), items.end(), Comparator);

  for (int k = 0; k < K; ++k) {
    int c;
    scanf("%d", &c);
    bags.insert(c);
  }

  int64_t ans = 0;
  for (const auto& item : items) {
    auto result = bags.lower_bound(item.first);
    if (result != bags.end()) {
      ans += item.second;
      bags.erase(result);
    }
  }

  printf("%lld\n", ans);

  return 0;
}