// Hoofball
// http://www.usaco.org/index.php?page=viewproblem2&cpid=808

#include <bits/stdc++.h>

using namespace std;

int Pass2Whom(const vector<int>& pos, int me) {
  int l = 1e9;
  int r = 1e9;
  if (me - 1 >= 0) {
    l = pos[me] - pos[me - 1];
  }
  if (me + 1 < pos.size()) {
    r = pos[me + 1] - pos[me];
  }

  if (l == 1e9 && r == 1e9) return me;  // only one cow
  if (l <= r) return me - 1;
  return me + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> pos(N);
  for (int i = 0; i < N; ++i) {
    cin >> pos[i];
  }

  sort(pos.begin(), pos.end());

  vector<int> get_cnts(N, 0);
  for (int i = 0; i < N; ++i) {
    get_cnts[Pass2Whom(pos, i)]++;
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (get_cnts[i] == 0) ans++;
    if (i < Pass2Whom(pos, i) && Pass2Whom(pos, Pass2Whom(pos, i)) == i &&
        get_cnts[i] == 1 && get_cnts[Pass2Whom(pos, i)] == 1) {
      ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}