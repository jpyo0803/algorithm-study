// 유학 금지
// https://www.acmicpc.net/problem/2789

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string censor = "CAMBRIDGE";

  string str;
  cin >> str;

  for (auto ch : str) {
    bool ok = true;
    for (auto ch2 : censor) {
      if (ch == ch2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << ch;
    }
  }
  cout << "\n";

  return 0;
}