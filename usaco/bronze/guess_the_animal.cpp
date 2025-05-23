// Guess the Animal (Bronze)
// https://www.acmicpc.net/problem/17029

#include <bits/stdc++.h>

using namespace std;

int n, k;
set<string> cs[105];

int UnionSize(const set<string>& a, const set<string>& b) {
  auto u = a;
  for (auto& e : b) {
    u.insert(e);
  }
  return u.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string who;
    cin >> who;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      string c;
      cin >> c;
      cs[i].insert(c);
    }
  }

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int usize = UnionSize(cs[i], cs[j]);
      ans = max(ans, (int)cs[i].size() + (int)cs[j].size() - usize);
    }
  }
  cout << ans + 1 << "\n";

  return 0;
}