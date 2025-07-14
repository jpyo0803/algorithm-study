// D - Conflict 2 (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_d

#include <bits/stdc++.h>

using namespace std;

int n, q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  vector<tuple<int, int, string>> qv(q);
  for (int i = 0; i < q; ++i) {
    int a, b;
    string s;
    cin >> a >> b;
    if (a == 2) cin >> s;
    qv[i] = tie(a, b, s);
  }

  /*
    operation 1: copy from server to PC 'b'
    operation 2: append 's' to PC 'b'
    operation 3: copy from pc 'b' to server
  */

  int curr = 0;
  string ans;
  for (int i = q - 1; i >= 0; --i) {
    int a, b;
    string s;
    tie(a, b, s) = qv[i];

    if (a == 1) {
      if (curr == b) curr = 0;
    } else if (a == 2) {
      if (curr == b) {
        reverse(s.begin(), s.end());
        ans += s;
      }
    } else {
      if (curr == 0) curr = b;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << "\n";

  return 0;
}