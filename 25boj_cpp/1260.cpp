// DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <bits/stdc++.h>

using namespace std;

int n, m, v;

int adj_mat[1010][1010]; //4mb
vector<int> adj_list[1010]; // 4mb

void SolveDfs() {
  stack<int> stk;

  vector<bool> visited(n + 10, false);
  stk.push(v);

  vector<int> ans;
  while (stk.empty() == false) {
    int x = stk.top();
    stk.pop();

    if (visited[x] == true) continue;

    ans.push_back(x);
    visited[x] = true;

    int len = adj_list[x].size();
    for (int i = len - 1; i >= 0; --i) {
      int y = adj_list[x][i];
      if (visited[y] == true) continue;
      stk.push(y);
    }
  }

  for (auto e : ans) {
    cout << e + 1 << " ";
  }
  cout << "\n";
}

void SolveBfs() {
  queue<int> que;

  vector<bool> visited(n + 10, false);

  que.push(v);

  vector<int> ans;

  while (que.empty() == false) {
    int x = que.front();
    que.pop();

    if (visited[x] == true) continue;
    visited[x] = true;
    ans.push_back(x);

    for (auto y : adj_list[x]) {
      if (visited[y] == true) continue;
      que.push(y);
    }
  }

  for (auto e : ans) {
    cout << e + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> v;
  v--;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj_mat[x][y] = adj_mat[y][x] = true;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (adj_mat[i][j] == true) { // ensures lower adj vertex is tried first
        adj_list[i].push_back(j);
      } 
    }
  }

  SolveDfs();
  SolveBfs();

  return 0;
}