// 쉐이드 커튼 위 먼지는 쌓이는 중
// https://www.acmicpc.net/problem/33511

#include <bits/stdc++.h>

using namespace std;

int n, m;

int ans[2005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  n = arr.size();

  vector<int> diff_pos;
  for (int j = 0; j < m; ++j) {
    int v = arr[0][j];
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (arr[i][j] != v) {
        ok = false;
        break;
      }
    }
    if (!ok) diff_pos.push_back(j);
  }

  if (n == 1) {  // same as diff pos == 0
    ans[0] = 0;
    for (int i = 1; i < m; ++i) ans[i] = arr[0][i];
  } else if (diff_pos.size() == 1) {
    for (int i = 0; i < m; ++i) {
      if (diff_pos[0] == i)
        ans[i] = 0;
      else
        ans[i] = arr[0][i];
    }
  } else {  // diff_pos.size() >= 2
    for (int i = 0; i < m; ++i) {
      bool ok = true;
      for (auto j : diff_pos) {
        if (i == j) {
          ok = false;
          break;
        }
      }
      if (ok) ans[i] = arr[0][i];
    }

    int a = diff_pos[0];
    int b = diff_pos[1];
    if (n == 2) {  // n == 2 && diff_pos.size() == 2
      ans[a] = arr[0][a];
      ans[b] = arr[1][b];
    } else {  // n >= 3 && diff_pos.size() >= 2
      set<int> cp;
      for (auto e : diff_pos) cp.insert(e);
      vector<int> remv;

      for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (auto k : cp) {
            if (arr[i][k] != arr[j][k]) continue;
            ans[k] = arr[i][k];
            remv.push_back(k);
          }

          for (auto e : remv) cp.erase(e);
          remv.clear();
        }
      }

      if (cp.size()) { // cp.size() is at most 1, also implies diff_pos was 2, 
        // if diff_pos.size() >= 3, then this never happens
        int target = *cp.begin();
        int other = *cp.begin() == a ? b : a;
        for (int i = 0; i < n; ++i) {
          if (arr[i][other] == ans[other]) continue;
          ans[target] = arr[i][target];
          break;
        }
      }
    }
  }

  for (int i = 0; i < m; ++i) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}