// Caesar Cipher
// https://www.acmicpc.net/problem/15874

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k, s;
  cin >> k >> s;
  cin.get();

  string line;
  getline(cin, line);

  for (int i = 0; i < s; ++i) {
    char ch = line[i];
    if (ch >= 'a' && ch <= 'z') {
      char off = (ch - 'a' + k) % 26;
      cout << (char)(off + 'a');
    } else if (ch >= 'A' && ch <= 'Z') {
      char off = (ch - 'A' + k) % 26;
      cout << (char)(off + 'A');
    } else {
      cout << ch;
    }
  }

  return 0;
}