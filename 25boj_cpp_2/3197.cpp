// 백조의 호수
// https://www.acmicpc.net/problem/3197

#include <bits/stdc++.h>

using namespace std;

char arr[1505][1505];

int r, c;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;

  priority_queue<pair<int, pair<int, int>>> pq;

  vector<pair<int, int>> lpts;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'L') {
        lpts.emplace_back(i, j);
        pq.emplace(0, pair<int, int>(i, j));
      } else if (arr[i][j] == '.') {
        pq.emplace(0, pair<int, int>(i, j));
      }
    }
  }

  assert(lpts.size() == 2);

  vector<vector<int>> dist(r, vector<int>(c, 1e9));

  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();

    int cost = -x.first;
    int ui = x.second.first;
    int uj = x.second.second;

    // if (dist[ui][uj] <= cost) continue;
    // dist[ui][uj] = cost;

    for (int i = 0; i < 4; ++i) {
      int vi = ui + dx[i];
      int vj = uj + dy[i];

      if (vi < 0 || vi >= r || vj < 0 || vj >= c) continue;
      int nc = cost + (arr[vi][vj] == 'X');
      if (dist[vi][vj] > nc) {
        pq.emplace(-nc, pair<int, int>(vi, vj));
        dist[vi][vj] = nc;
      }
    }
  }

  // for (int i = 0; i < r; ++i) {
  //   for (int j = 0; j < c; ++j) {
  //     if (dist[i][j] == 1e9) cout << '7' << ' ';
  //     else cout << dist[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  vector<vector<int>> dist2(r, vector<int>(c, 1e9));
  pq.emplace(0, lpts[0]);

  int ans = 0;

  bool done = false;
  while (done == false && pq.empty() == false) {
    auto x = pq.top();
    pq.pop();

    int cost = -x.first;
    int ui = x.second.first;
    int uj = x.second.second;
    // cout << "cost : " << cost << " / " << ui << ", " << uj <<  endl;

    ans = max(ans, cost);

    // if (dist2[ui][uj] <= cost) continue;
    // dist2[ui][uj] = cost;

    for (int i = 0; i < 4; ++i) {
      int vi = ui + dx[i];
      int vj = uj + dy[i];

      if (vi < 0 || vi >= r || vj < 0 || vj >= c) continue;
      if (arr[vi][vj] == 'L' && lpts[1].first == vi && lpts[1].second == vj) {
        done = true;
        break;
      }
      int nc = dist[vi][vj];
      if (dist2[vi][vj] > nc) {
        pq.emplace(-nc, pair<int, int>(vi, vj));
        dist2[vi][vj] = nc;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}