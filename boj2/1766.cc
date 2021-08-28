//
// Question bank
// Problem: https://www.acmicpc.net/problem/1766
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX{32000};
int N, M, u, v;

vector<int> adj_list[MAX + 1];
priority_queue<int, vector<int>, greater<int>> pq;
int in_degree[MAX + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    adj_list[u].push_back(v);
    in_degree[v] += 1;
  }

  for (int i = 1; i <= N; i++) {
    if (in_degree[i] == 0) {
      pq.push(i);
    }
  }

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();
    cout << u << " ";
    for (auto v : adj_list[u]) {
      in_degree[v] -= 1;
      if (in_degree[v] == 0) {
        pq.push(v);
      }
    }
  }
  return 0;
}
