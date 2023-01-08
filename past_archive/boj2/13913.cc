//
// Hide and Seek 4
// Problem: https://www.acmicpc.net/problem/13913
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX{100000};
const int INF{100000000};
int N, K;
int level[MAX + 1];
int parent[MAX + 1];

int bfs(int n, int k) {
  vector<int> frontier, next;
  frontier.push_back(n);

  int c_level{0};
  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      if (u == k) {
        return c_level;
      }
      int v{u + 1};
      if (v <= MAX && c_level <= level[v]) {
        level[v] = c_level;
        next.push_back(v);
        parent[v] = u;
      }
      v = u - 1;
      if (v >= 0 && c_level <= level[v]) {
        level[v] = c_level;
        next.push_back(v);
        parent[v] = u;
      }
      v = u * 2;
      if (v >= 0 && v <= MAX && c_level <= level[v]) {
        level[v] = c_level;
        next.push_back(v);
        parent[v] = u;
      }
    }
    c_level += 1;
    swap(frontier, next);
  }
}

void print_backward(int p) {
  if (p == -1) return;
  print_backward(parent[p]);
  cout << p << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> K;
  for (int i = 0; i <= MAX; i++) {
    level[i] = INF;
  }
  cout << bfs(N, K) << endl;
  parent[N] = -1;
  print_backward(K);

  return 0;
}
