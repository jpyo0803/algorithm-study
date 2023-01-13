// Block Game
// http://www.usaco.org/index.php?page=viewproblem2&cpid=664

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> ans(26);

  for (int i = 0; i < N; ++i) {
    string a, b;
    cin >> a >> b;

    vector<int> cnt_a(26), cnt_b(26);
    for (auto ch : a) {
      ++cnt_a[ch - 'a'];
    }
    for (auto ch : b) {
      ++cnt_b[ch - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      ans[i] += max(cnt_a[i], cnt_b[i]);
    }
  }

  for (auto e : ans) {
    cout << e << "\n";
  }

  return 0;
}