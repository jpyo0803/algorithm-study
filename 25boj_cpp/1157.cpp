// 단어 공부
// https://www.acmicpc.net/problem/1157

#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a;
  cin >> a;

  int offset = 'a' - 'A';

  for (auto ch : a) {
    if (ch >= 'a' && ch <= 'z') {
      ch -= offset;
    }

    cnt[ch]++;
  }

  bool redundant = true;

  char ans;
  int max_cnt = -1;
  for (char ch = 'A'; ch <= 'Z'; ++ch) {
    if (cnt[ch] > max_cnt) {
      max_cnt = cnt[ch];
      ans = ch;
      redundant = false;
    } else if (cnt[ch] == max_cnt) {
      redundant = true;
    }
  }

  if (redundant == true) {
    cout << "?\n";
  } else {
    cout << ans << "\n";
  }

  return 0;
}