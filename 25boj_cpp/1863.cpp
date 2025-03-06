// 스카이라인 쉬운거
// https://www.acmicpc.net/problem/1863

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i].first >> vv[i].second;  
  vv.emplace_back(vv[n - 1].first + 1, 0);

  
  stack<int> stk;
  stk.push(0);
  
  int ans = 0;
  // stack if larger than the previous one
  // pop until encounter smaller or equal one (or until it is empty)
  // if equal, do not add
  // if smaller, add
  // as you pop you count
  for (auto e : vv) {
    int y = e.second;
    if (y > stk.top()) {
      stk.push(y);
    } else {
      while (y < stk.top()) {
        stk.pop();
        ans++;
      }
      if (y > stk.top()) {
        stk.push(y);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}