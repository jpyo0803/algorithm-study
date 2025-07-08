// Photoshoot (Bronze)
// https://www.acmicpc.net/problem/24980

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  string s;
  cin >> s;

  int ans = 0;

  string last;
  for (int i = 0; i < n; i += 2) {
    string a = s.substr(i, 2);
    if (a[0] == a[1]) continue;
    if (a == last) continue;
    ans++;
    last = a;
  }
  if (last == "HG") ans--;
  cout << ans << "\n";

  return 0;
}