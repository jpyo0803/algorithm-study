// Why Did the Cow Cross the Road II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=712

#include <bits/stdc++.h>

using namespace std;

pair<int, int> pos[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  for (int i = 1; i <= s.length(); ++i) {
    if (pos[s[i - 1]].first == 0) {
      pos[s[i - 1]].first = i;
    } else {
      pos[s[i - 1]].second = i;
    }
  }

  int ans = 0;

  auto check = [](int a, int b, int c, int d) {
    if (c < b && b < d && a < c) return true;
    return false;
  };

  for (char i = 'A'; i < 'Z'; ++i) {
    for (char j = i + 1; j <= 'Z'; ++j) {
      int a = pos[i].first, b = pos[i].second;
      int c = pos[j].first, d = pos[j].second;
      if (check(a, b, c, d))
        ++ans;
      else if (check(c, d, a, b))
        ++ans;
    }
  }

  cout << ans << "\n";

  return 0;
}