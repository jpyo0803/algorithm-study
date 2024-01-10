// 팰린드롬 만들기
// https://www.acmicpc.net/problem/1213

#include <bits/stdc++.h>

using namespace std;

char buf[55];
int cnt[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int N = s.length();

  for (auto ch : s) {
    ++cnt[ch - 'A'];
  }

  int odd_cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] % 2) odd_cnt++;
  }

  if (odd_cnt >= 2) {
    cout << "I'm Sorry Hansoo\n";
  } else {
    int pos = 0;
    for (int i = 0; i < 26; ++i) {
      while (cnt[i] > 1) {
        buf[N - 1 - pos] = buf[pos] = i + 'A';
        cnt[i] -= 2;
        pos++;
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        buf[pos] = i + 'A';
      }
    }
    for (int i = 0; i < N; ++i) {
      cout << buf[i];
    }
    cout << "\n";
  }

  return 0;
}