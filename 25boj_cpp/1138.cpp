// 한 줄로 서기
// https://www.acmicpc.net/problem/1138

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> left_cnt(n);
  for (int i = 0; i < n; ++i) cin >> left_cnt[i];

  vector<int> ans(n, 0);

  for (int i = n - 1; i >= 0; --i) {
    if (ans[left_cnt[i]] != 0) {
      for (int j = n - 1; j > left_cnt[i]; --j) {
        ans[j] = ans[j - 1];
      }
    }
    ans[left_cnt[i]] = i + 1;
  }

  for (auto e : ans) {
    cout << e << " ";
  }
  cout << "\n";

  return 0;
}