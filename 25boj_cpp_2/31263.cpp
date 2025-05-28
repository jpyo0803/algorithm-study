// 대한민국을 지키는 가장 긴 힘
// https://www.acmicpc.net/problem/31263

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;

  int i = 0;
  int ans = 0;
  while (i < n) {
    while (s[i] == '0') i--;

    int j = 2;
    while (i + j > n) j--;

    while (true) {
      int cand = stoi(s.substr(i, j + 1));
      if (cand >= 1 && cand <= 641) break;
      j--;
    }

    i += j + 1;
    ans++;
  }

  cout << ans << "\n";

  return 0;
}