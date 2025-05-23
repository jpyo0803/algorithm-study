// Why Did the Cow Cross the Road II (Bronze)
// https://www.acmicpc.net/problem/14468

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int ans = 0;
  for (char x = 'A'; x < 'Z'; ++x) {
    for (char y = x + 1; y <= 'Z'; ++y) {
      // Q: do x's and y's interleave?
      pair<int, int> apos, bpos;
      apos.first = bpos.first = -1;
      for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        if (ch == x) {
          if (apos.first == -1)
            apos.first = i;
          else
            apos.second = i;
        } else if (ch == y) {
          if (bpos.first == -1)
            bpos.first = i;
          else
            bpos.second = i;
        }
      }
      if ((apos.first < bpos.first && bpos.first < apos.second &&
           apos.second < bpos.second) ||
          (bpos.first < apos.first && apos.first < bpos.second &&
           bpos.second < apos.second)) {
        ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}