// 물통 
// https://www.acmicpc.net/problem/2251

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool vis[205][205];
int cap[3];
int n;
vector<int> ans;

void Solve(array<int, 3> curr) {
  for (int i = 0; i < 2; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      int x = curr[i], y = curr[j];
      int cx = cap[i], cy = cap[j];
      if (x > 0 && cy - y > 0) {
        int amt = min(x, cy - y);
        array<int, 3> next;
        next[i] = x - amt, next[j] = y + amt, next[3 - i - j] = n - x - y;
        if (vis[next[0]][next[1]]) continue;
        vis[next[0]][next[1]] = true;
        if (next[0] == 0) ans.push_back(next[2]);
        Solve(next);
      }
      if (y > 0 && cx - x > 0) {
        int amt = min(y, cx - x);
        array<int, 3> next;
        next[i] = x + amt, next[j] = y - amt, next[3 - i - j] = n - x - y;
        if (vis[next[0]][next[1]]) continue;
        vis[next[0]][next[1]] = true;
        if (next[0] == 0) ans.push_back(next[2]);
        Solve(next);     
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> cap[0] >> cap[1] >> cap[2];
  n = cap[2];

  vis[0][0] = true;
  ans.push_back(n);
  Solve({0, 0, n});

  sort(ans.begin(), ans.end());

  for (auto e : ans) cout << e << " ";
  cout << "\n";

  return 0;
}