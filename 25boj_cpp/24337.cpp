// 가희와 탑
// https://www.acmicpc.net/problem/24337

#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a + b - 1 > n) {
    cout << "-1\n";
    return;
  }

  vector<int> ans;
  int pivot = max(a, b);
  for (int i = 1; i <= a - 1; ++i) ans.push_back(i);
  ans.push_back(pivot);
  for (int i = b - 1; i >= 1; --i) ans.push_back(i);

  int fill_cnt = n - ans.size();
  cout << ans[0] << " ";
  while (fill_cnt--) cout << "1 ";
  for (int i = 1; i < ans.size(); ++i) cout << ans[i] << " ";

  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve(); 

  return 0;
}