// 촌수계산
// https://www.acmicpc.net/problem/2644

#include <bits/stdc++.h>

using namespace std;

int n, a, b, m;

int p[105];

int GetParent(int c) {
  if (p[c] == 0) return -1;
  return p[c];
}

int IsAncestor(int a, int b) {
  int cnt = 0;
  while (a != b) {
    b = GetParent(b);
    if (b == -1) return -1;
    cnt++;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> a >> b;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;  // x parent
    cin >> x >> y;
    p[y] = x;
  }

  int ac = 0, bc = 0;
  int ans = -1;
  while (a != -1) {
    bc = IsAncestor(a, b);
    if (bc != -1) {
      ans = ac + bc;
      break;
    }
    a = GetParent(a);
    ac++;
  }

  cout << ans << "\n";

  return 0;
}