// Sum of Two Values (CSES)
// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, X;
  cin >> N >> X;
  map<int, int> m;

  bool ok = false;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    int c = X - a;
    if (m.count(c) > 0) {
      cout << m[c] << " " << i + 1 << "\n";
      ok = true;
      break;
    }
    m[a] = i + 1;
  }
  if (!ok) {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}