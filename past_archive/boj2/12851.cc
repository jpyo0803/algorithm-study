//
// Hide and Seek 2
// Problem: https://www.acmicpc.net/problem/12851
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX{100000};
const int INF{100000000};
int N, K;
int sec, possiblity{0};

int level[MAX + 1];

void bfs(int n, int k) {
  vector<int> frontier, next;
  frontier.push_back(n);

  int ans{0};
  int c_level = 0;
  bool found{false};

  while (!frontier.empty() && !found) {
    next.clear();
    for (auto u : frontier) {
      if (u == k) {
        possiblity += 1;
        sec = c_level;
        found = true;
      } else {
        int v{u - 1};
        if (v >= 0 && c_level <= level[v]) {
          level[v] = c_level;
          next.push_back(v);
        }
        v = u + 1;
        if (v <= MAX && c_level <= level[v]) {
          level[v] = c_level;
          next.push_back(v);
        }
        v = u * 2;
        if (v > 0 && v <= MAX && c_level <= level[v]) {
          level[v] = c_level;
          next.push_back(v);
        }
      }
    }
    c_level += 1;
    swap(frontier, next);
  }
}

int main() {
  cin >> N >> K;
  for (int i = 0; i <= MAX; i++) {
    level[i] = INF;
  }
  bfs(N, K);
  cout << sec << endl;
  cout << possiblity;
  return 0;
}