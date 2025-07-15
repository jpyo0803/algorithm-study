// Swapity Swap (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int n, k, a1, a2, b1, b2;

int Swap(int x) {
  if (a1 <= x && x <= a2) x = a1 + a2 - x;
  if (b1 <= x && x <= b2) x = b1 + b2 - x;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  vector<int> ans(n);
  cin >> a1 >> a2 >> b1 >> b2;

  for (int i = 1; i <= n; ++i) {
    int curr = i;

    int cnt = 0;
    while (true) {
      curr = Swap(curr);
      cnt++;
      if (curr == i) break;
    }

    // curr == i
    for (int j = 0; j < k % cnt; ++j) {
      curr = Swap(curr);
    }
    ans[curr - 1] = i;
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}