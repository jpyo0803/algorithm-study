// D - String Rotation (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_d

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; ++i) {
      if (s[i] > s[i + 1]) {
        int j = i + 1;
        while (j + 1 < n && s[i] >= s[j + 1]) {
          j++;
        }
        char tmp = s[i];
        for (int k = i; k < j; ++k) {
          s[k] = s[k + 1];
        }
        s[j] = tmp;
        break;
      }
    }
    cout << s << "\n";
  }

  return 0;
}