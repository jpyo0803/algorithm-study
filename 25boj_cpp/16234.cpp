// 인구 이동
// https://www.acmicpc.net/problem/16234

#include <bits/stdc++.h>

using namespace std;

int n, l, r;

int arr[55][55];
bool visited[55][55];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool Dfs(int i, int j) {
  vector<pair<int, int>> trace; 

  stack<pair<int, int>> ss;
  ss.emplace(i, j);
  trace.emplace_back(i, j);
  visited[i][j] = true;

  while (ss.empty() == false) {
    auto u = ss.top();
    ss.pop();
    int ui = u.first;
    int uj = u.second;

    for (int i = 0; i < 4; ++i) {
      int vi = ui + dx[i];
      int vj = uj + dy[i];
      if (vi < 0 || vi >= n || vj < 0 || vj >= n) continue;
      if (visited[vi][vj]) continue;
      int diff = abs(arr[ui][uj] - arr[vi][vj]);
      if (diff < l || diff > r) continue;
      ss.emplace(vi, vj);
      visited[vi][vj] = true;
      trace.emplace_back(vi, vj);
    }
  }

  int avg = 0;
  for (auto x : trace) {
    avg += arr[x.first][x.second];
  }
  avg /= trace.size();
  for (auto x : trace) {
    arr[x.first][x.second] = avg;
  }
  return trace.size() > 1;
}

bool Solve() {
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) 
      visited[i][j] = false;

  bool ok = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (visited[i][j] == false) ok |= Dfs(i, j);
    }
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  while (true) {
    bool ok = Solve();
    if (ok == false) break;
    ans++;
  }

  cout << ans << "\n";
  
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}