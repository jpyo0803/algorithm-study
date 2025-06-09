// 구간 합 구하기
// https://www.acmicpc.net/problem/2042

#include <bits/stdc++.h>

using namespace std;

int n, m, k, a, b;
long long c;

long long arr[1000005];
long long tree[1000005];

int P(int x) { return x & -x; }

void Update(int idx, long long new_val) {
  long long old_val = arr[idx];
  arr[idx] = new_val;

  while (idx <= n) {
    tree[idx] -= old_val;
    tree[idx] += new_val;
    idx += P(idx);
  }
}

long long Sum(int x) {
  // sum(1, x)
  long long s = 0;
  while (x > 0) {
    s += tree[x];
    x -= P(x);
  }
  return s;
}

long long Query(int a, int b) { return Sum(b) - Sum(a - 1); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    Update(i, x);
  }

  for (int i = 0; i < m + k; ++i) {
    cin >> a >> b >> c;
    if (a == 1) {
      Update(b, c);
    } else {
      cout << Query(b, (int)c) << "\n";
    }
  }

  return 0;
}