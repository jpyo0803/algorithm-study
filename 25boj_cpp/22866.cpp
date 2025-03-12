// 탑 보기
// https://www.acmicpc.net/problem/22866

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100010];
int closest[100010];
int cnt[100010];
int ans[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) closest[i] = 1e9;

  stack<pair<int, int>> stk;
  for (int i = 0; i < n; ++i) {
    // process left
    int h = arr[i];
    while (stk.size() && stk.top().first <= h) {
      stk.pop();
    }

    cnt[i] = stk.size();
    if (stk.size() && i - stk.top().second < closest[i]) {
      closest[i] = i - stk.top().second;
      ans[i] = stk.top().second;
    }

    stk.emplace(h, i);
  }

  while (stk.size()) stk.pop();

  for (int i = n - 1; i >= 0; --i) {
    // process right
    int h = arr[i];
    while (stk.size() && stk.top().first <= h) {
      stk.pop();
    }

    cnt[i] += stk.size();
    if (stk.size() && stk.top().second - i < closest[i]) {
      closest[i] = stk.top().second - i;
      ans[i] = stk.top().second;
    }
    stk.emplace(h, i);
  }

  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) cout << 0 << "\n";
    else {
      cout << cnt[i] << " " << ans[i] + 1 << "\n";
    }
  } 

  return 0;
}