// A - Not Found (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_a

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  for (char ch = 'a'; ch <= 'z'; ++ch) {
    bool ok = true;
    for (auto ch2 : s) {
      if (ch == ch2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << ch << "\n";
      break;
    }
  }

  return 0;
}