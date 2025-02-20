// 탑
// https://www.acmicpc.net/problem/2493

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  stack<pair<int, int>> stk; // height, and idx

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    int ans = 0;
    while (stk.empty() == false && stk.top().first < x) {
      stk.pop();
    }
    if (stk.empty() == false) ans = stk.top().second + 1;
    cout << ans << " ";

    stk.emplace(x, i);
  } 
  cout << "\n";

  return 0;
}