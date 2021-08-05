//
// Minimum and Maximum values
// Link: https://www.acmicpc.net/problem/2357
//

#include <cstdio>
#include <utility>
#include <vector>

constexpr int INF = 1000000001;

using namespace std;

vector<int> numbers;
int N, M, num, a, b;

int Minimum(int x, int y) { return x < y ? x : y; }
int Maximum(int x, int y) { return x > y ? x : y; }

struct RMQ {
  int n;
  vector<pair<int, int>> range_min_max;

  RMQ(const vector<int>& array) {
    n = array.size();
    range_min_max.resize(n * 4);
    init(array, 0, n - 1, 1);
  }

  pair<int, int> init(const vector<int>& array, int left, int right, int node) {
    if (left == right) {
      range_min_max[node].first = range_min_max[node].second = array[left];
      return range_min_max[node];
    }

    int mid = (left + right) / 2;
    auto p1 = init(array, left, mid, node * 2);
    auto p2 = init(array, mid + 1, right, node * 2 + 1);
    range_min_max[node].first = Minimum(p1.first, p2.first);
    range_min_max[node].second = Maximum(p1.second, p2.second);
    return range_min_max[node];
  }

  pair<int, int> query(int left, int right, int node, int node_left,
                       int node_right) {
    if (node_right < left || node_left > right) return make_pair(INF, 0);
    if (node_left >= left && node_right <= right) return range_min_max[node];

    int mid = (node_left + node_right) / 2;
    auto p1 = query(left, right, node * 2, node_left, mid);
    auto p2 = query(left, right, node * 2 + 1, mid + 1, node_right);
    return make_pair(Minimum(p1.first, p2.first),
                     Maximum(p1.second, p2.second));
  }

  pair<int, int> query(int left, int right) {
    return query(left, right, 1, 0, n - 1);
  }
};

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num);
    numbers.push_back(num);
  }

  RMQ* rmq = new RMQ(numbers);

  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    auto ans = rmq->query(a - 1, b - 1);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}