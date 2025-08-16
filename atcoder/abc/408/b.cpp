// B - Compression (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_b

#include <bits/stdc++.h>

using namespace std;

bool seen[105];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int seen_cnt = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (seen[x] == false) {
      seen[x] = true;
      seen_cnt++;
    }
  }

  cout << seen_cnt << "\n";
  for (int i = 1; i <= 100; ++i) {
    if (seen[i]) cout << i << " ";
  }
  cout << "\n";

  return 0;
}