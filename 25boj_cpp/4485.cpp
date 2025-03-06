// 녹색 옷 입은 애가 젤다지?
// https://www.acmicpc.net/problem/4485

#include <bits/stdc++.h>

using namespace std;

int n;

int arr[130][130];
int dst[130][130];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  int p = 1;
  while (n > 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> arr[i][j];
        dst[i][j] = 1e9; // reset
      }
    }
  
    priority_queue<pair<int, pair<int, int>>> pq; // cost, u
    pq.emplace(-arr[0][0], pair<int, int>{0, 0});

    while (pq.empty() == false) {
      auto x = pq.top();
      pq.pop();
      int cost = -x.first; // 
      int ux = x.second.first;
      int uy = x.second.second;

      for (int i = 0; i < 4; ++i) {
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        if (vx < 0 || vx >= n || vy < 0 || vy >= n) continue;
        int next_cost = cost + arr[vx][vy];
        if (next_cost >= dst[vx][vy]) continue;
        pq.emplace(-next_cost, pair<int, int>(vx, vy));
        dst[vx][vy] = next_cost;
      }
    }

    cout << "Problem " << p << ": " << dst[n - 1][n - 1] << "\n";
    p++;

    cin >> n;
  }

  return 0;
}