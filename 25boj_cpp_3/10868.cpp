// 최솟값
// https://www.acmicpc.net/problem/10868

#include <bits/stdc++.h>

using namespace std;

int n, m;
int tree[200005];

void Update(int pos, int val) {
  pos += n;
  tree[pos] = val;
  for (pos /= 2; pos >= 1; pos /= 2) tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}

int Query(int a, int b) {
  a += n, b += n;
  int ret = 1e9;
  while (a <= b) {
    if (a % 2) ret = min(ret, tree[a++]);
    if (b % 2 == 0) ret = min(ret, tree[b--]);
    a /= 2, b /= 2;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    Update(i, val);
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << Query(a, b) << "\n";
  }

  return 0;
}