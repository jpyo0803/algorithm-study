// 암호
// https://www.acmicpc.net/problem/1718

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string p, k;
  getline(cin, p);
  cin >> k;

  for (int i = 0; i < p.size(); ++i) {
    char ch = p[i];
    if (ch == ' ') {
      cout << ch;
    } else {
      char tmp = ch - k[i % k.size()] - 1;
      if (tmp < 0) {
        tmp += 26;
      }
      cout << (char)(tmp + 'a');
    }
  }

  return 0;
}