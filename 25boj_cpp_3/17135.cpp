// 캐슬 디펜스 
// https://www.acmicpc.net/problem/17135

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, d;

int Dist(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> d;

  vector<vector<int>> arr(n, vector<int>(m));

  int ec = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j]) ec++;
    }
  }

  int ans = 0;
  for (int x = 0; x < m; ++x) {
    for (int y = x + 1; y < m; ++y) {
      for (int z = y + 1; z < m; ++z) {
        int cand = 0;
        auto tmp = arr;
        int ec2 = ec;
        while (ec2 > 0) {
          pair<int, int> xt = {-1, -1};
          pair<int, int> yt = {-1, -1};
          pair<int, int> zt = {-1, -1};

          int mix = 1e9;
          int miy = 1e9;
          int miz = 1e9;

          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
              if (tmp[i][j] == 0) continue;
              int xd = Dist({n, x}, {i, j});
              int yd = Dist({n, y}, {i, j});
              int zd = Dist({n, z}, {i, j});
             
              if (xd <= d) {
                if (xd < mix) {
                  xt = {i, j};
                  mix = xd;
                } else if (xd == mix) {
                  if (xt.second > j) xt = {i, j};
                }
              }
              if (yd <= d) {
                if (yd < miy) {
                  yt = {i, j};
                  miy = yd;
                } else if (yd == miy) {
                  if (yt.second > j) yt = {i, j};
                }
              }
              if (zd <= d) {
                if (zd < miz) {
                  zt = {i, j};
                  miz = zd;
                } else if (zd == miz) {
                  if (zt.second > j) zt = {i, j};
                }
              }
            }
          }

          set<pair<int, int>> ss = {xt, yt, zt};
          for (auto e : ss) {
            if (e.first == -1) continue;
            cand++;
            tmp[e.first][e.second] = 0; 
            ec2--;
          }
          vector<vector<int>> tmp2(n, vector<int>(m , 0));
          for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
              tmp2[i][j] = tmp[i - 1][j];
            }
          }
          for (int j = 0; j < m; ++j) {
            if (tmp[n - 1][j] == 1) ec2--;
          }
          swap(tmp, tmp2);
        }

        ans = max(ans, cand);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}