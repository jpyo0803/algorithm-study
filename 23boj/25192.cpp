// 인사성 밝은 곰곰이
// https://www.acmicpc.net/problem/25192

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  set<string> ss;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    if (s == "ENTER") {
      ss.clear();
    } else {
      auto it = ss.find(s);
      if (it == ss.end()) {
        ss.insert(s);
        ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}