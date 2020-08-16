//
// Minimum Value
// Link: https://www.acmicpc.net/problem/10868
//

#include <cstdio>
#include <vector>

constexpr int INF = 2000000000;
int N, M, a, b;

int Min(int x, int y) { return x < y ? x : y; }

using namespace std;

vector<int> numbers;

struct RMQ {
  vector<int> arr;
  int n;

  RMQ(const vector<int>& numbers) {
    n = numbers.size();
    arr.resize(n * 4);
    init(1, 0, n - 1);
  }
  int init(int node, int left, int right) {
    if (left == right) return arr[node] = numbers[left];
    int mid = (left + right) / 2;
    arr[node] =
        Min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
    return arr[node];
  }
  int find(int left, int right, int node, int node_left, int node_right) {
    if (node_right < left || right < node_left) return INF;
    if (left <= node_left && node_right <= right) return arr[node];
    int mid = (node_left + node_right) / 2;
    return Min(find(left, right, node * 2, node_left, mid),
               find(left, right, node * 2 + 1, mid + 1, node_right));
  }
  int find(int left, int right) { return find(left, right, 1, 0, n - 1); }
};

int main() {
  scanf("%d%d", &N, &M);
  numbers.resize(N);
  for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);

  RMQ* rmq = new RMQ(numbers);

  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", rmq->find(a - 1, b - 1));
  }

  return 0;
}