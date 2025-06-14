// Cities and States (Silver)
// https://www.acmicpc.net/problem/14171


#include <bits/stdc++.h>

using namespace std;

int n;

int GetIdx(const string& str) {
  int ret = 0;
  int f = 1;
  for (int i = 0; i < str.size(); ++i) {
    ret += (str[i] - 'A') * f;
    f *= 26;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<string, string>> vv(n);
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    vv[i].first = a.substr(0, 2);
    vv[i].second = b;
  }

  int ans = 0;

  vector<int> seen(26 * 26 * 26 * 26, 0);
  for (const auto& e : vv) {
    if (e.first != e.second) {
      ans += seen[GetIdx(e.first + e.second)];
      seen[GetIdx(e.second + e.first)]++;
    }
  }
  cout << ans << "\n";

  return 0;
}