// 부분 문자열
// https://www.acmicpc.net/problem/6550

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s, t;
  while (cin >> s >> t) {
    int x = 0;

    bool ok = false;
    for (auto ch : t) {
      if (ch == s[x]) {
        x++;
        if (x == s.length()) {
          ok = true;
          break;
        }
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}