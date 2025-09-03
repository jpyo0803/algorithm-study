// 나무 재테크 
// https://www.acmicpc.net/problem/16235

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, k, x, y, z;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

priority_queue<pair<ll, ll>> arr[12][12]; // ages
ll A[12][12]; 
ll nu[12][12]; // nutrient
ll dead[12][12];

ll b[12][12];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> A[i][j];
      nu[i][j] = 5;
    }
  }

  while (m--) {
    cin >> x >> y >> z;
    x--, y--;
    arr[x][y].emplace(-z, 1);
  }

  while (k--) {
    for (int s = 0; s < 4; ++s) {
      if (s == 0) { // spring
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            priority_queue<pair<ll, ll>> alive;
            while (arr[i][j].size()) {
              ll age = -arr[i][j].top().first;
              ll cnt = arr[i][j].top().second;
              arr[i][j].pop();

              ll eat_cnt = min(nu[i][j] / age, cnt);
              nu[i][j] -= eat_cnt * age;
              ll dead_cnt = cnt - eat_cnt;

              // cout << i + 1 << ", " << j + 1 << " : " << eat_cnt << " / " << dead_cnt << ", " << age << endl;
              if (eat_cnt > 0) {
                alive.emplace(-(age + 1), eat_cnt);
              }
              dead[i][j] += (age / 2) * dead_cnt;
            }
            swap(arr[i][j], alive);
          }
        } 
      } else if (s == 1) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            nu[i][j] += dead[i][j];
            dead[i][j] = 0;
          }
        }
      } else if (s == 2) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            auto tmp = arr[i][j];
            while (tmp.size()) {
              ll age = -tmp.top().first; 
              ll cnt = tmp.top().second;
              tmp.pop();
              if (age % 5 == 0) {
                for (int l = 0; l < 8; ++l) {
                  int ni = i + dx[l], nj = j + dy[l];
                  if (OutOfRange(ni, nj)) continue;
                  b[ni][nj] += cnt;
                }
              }
            }
          }
        }

        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (b[i][j] > 0) {
              arr[i][j].emplace(-1, b[i][j]);
              b[i][j] = 0;
            }
          }
        }
      } else {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            nu[i][j] += A[i][j];
          }
        }
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      while (arr[i][j].size()) {
        ans += arr[i][j].top().second;
        // if (i == 2 && j == 1) cout << arr[i][j].top().second << endl;
        arr[i][j].pop();
      }
    }
  }
  cout << ans << "\n";

  return 0;
}