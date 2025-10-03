// Modern Art (Platinum)
// https://www.acmicpc.net/problem/14522

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

struct Rect {
  int x1, y1, x2, y2;

  tuple<int, int, int, int> GetItems() const { return {x1, y1, x2, y2}; }
};

Rect rr[1000005];
int arr[1005][1005];
int ps[1005][1005];
bool seen[1000005];
bool impos[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  int seen_cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) continue;

      auto& rect = rr[arr[i][j]];
      if (seen[arr[i][j]] == false) {  // first seen
        rect.x1 = rect.x2 = i;
        rect.y1 = rect.y2 = j;
        seen[arr[i][j]] = true;
        seen_cnt++;
      }
      rect.x1 = min(rect.x1, i);
      rect.x2 = max(rect.x2, i);
      rect.y1 = min(rect.y1, j);
      rect.y2 = max(rect.y2, j);
    }
  }

  for (int i = 1; i <= n * n; ++i) {
    if (seen[i] == false) continue;
    int x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = rr[i].GetItems();

    ps[x1][y1]++;
    ps[x1][y2 + 1]--;
    ps[x2 + 1][y1]--;
    ps[x2 + 1][y2 + 1]++;
  }
  
  int elim_cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + ps[i][j];
      if (ps[i][j] > 1 && impos[arr[i][j]] == false) {
        impos[arr[i][j]] = true;
        elim_cnt++;
      }
    }
  }

  int ans = seen_cnt - elim_cnt;
  int unseen_cnt = n * n - seen_cnt;
  ans += unseen_cnt;
  if (seen_cnt == 1 && unseen_cnt > 0) ans--;
  cout << ans << "\n";

  return 0;
}