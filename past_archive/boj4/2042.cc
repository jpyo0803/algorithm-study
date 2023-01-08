//
// Finding Segment Sum
// Link: https://www.acmicpc.net/problem/2042
//

#include <cstdint>
#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMaxSize = 1000000;
int N, M, K, a, index, left, right;
int64_t num;
int64_t numbers[kMaxSize];

struct RSQ {
  int n;
  int64_t range_sum[kMaxSize * 4];

  RSQ(int64_t array[], int sz) {
    n = sz;
    init(array, 0, n - 1, 1);
  }

  int64_t init(int64_t array[], int left, int right, int node) {
    if (left == right) return range_sum[node] = array[left];
    int mid = (left + right) / 2;
    range_sum[node] = 0;
    range_sum[node] += init(array, left, mid, node * 2);
    range_sum[node] += init(array, mid + 1, right, node * 2 + 1);
    return range_sum[node];
  }

  int64_t query(int left, int right, int node, int node_left, int node_right) {
    if (node_right < left || node_left > right) return 0;
    if (node_left >= left && node_right <= right) return range_sum[node];
    int mid = (node_left + node_right) / 2;
    return query(left, right, node * 2, node_left, mid) +
           query(left, right, node * 2 + 1, mid + 1, node_right);
  }

  int64_t query(int left, int right) { return query(left, right, 1, 0, n - 1); }

  int64_t update(int index, int64_t new_value, int node, int node_left,
                 int node_right) {
    if (index < node_left || index > node_right) return range_sum[node];
    if (node_left == node_right) return range_sum[node] = new_value;
    int mid = (node_left + node_right) / 2;
    range_sum[node] = 0;
    range_sum[node] += update(index, new_value, node * 2, node_left, mid);
    range_sum[node] +=
        update(index, new_value, node * 2 + 1, mid + 1, node_right);
    return range_sum[node];
  }

  int64_t update(int index, int64_t new_value) {
    return update(index, new_value, 1, 0, n - 1);
  }
};

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &numbers[i]);
  }

  RSQ* rsq = new RSQ(numbers, N);

  for (int i = 0; i < M + K; i++) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%lld", &index, &num);
      rsq->update(index - 1, num);
    } else {
      scanf("%d%d", &left, &right);
      printf("%lld\n", rsq->query(left - 1, right - 1));
    }
  }
  return 0;
}