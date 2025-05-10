// 집합의 표현
// https://www.acmicpc.net/problem/1717

#include <bits/stdc++.h>

using namespace std;

int n, m;

int p[1000005];

int UF(int x) {
  if (p[x] == x) {
    return x;
  }

  int root = UF(p[x]);
  p[x] = root; // path compression
  return root;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i <= n; ++i) {
    p[i] = i;
  }

  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;

    int r1 = UF(a);
    int r2 = UF(b);
    if (op == 0) { // hap
      if (r1 != r2) {
        p[r2] = r1;
      }
    } else { // check
      cout << (r1 == r2 ? "YES\n" : "NO\n");
    }
  }

  return 0;
}