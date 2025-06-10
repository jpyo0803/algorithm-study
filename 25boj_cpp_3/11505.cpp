// 구간 곱 구하기
// https://www.acmicpc.net/problem/11505

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int n, m, k;
int offset;

int tree[1 << 21];

void Update(int idx, int new_val) {
  idx += offset;
  tree[idx] = new_val;

  for (idx /= 2; idx >= 1; idx /= 2) {
    tree[idx] = (int)(((long long)tree[idx * 2] * tree[idx * 2 + 1]) % kMod);
  }
}

int Query(int a, int b) {
  a += offset;
  b += offset;

  long long ret = 1;
  while (a <= b) {
    if (a % 2) { // right child
      ret *= tree[a++];
      ret %= kMod;
    }
    if (b % 2 == 0) {
      ret *= tree[b--];
      ret %= kMod;
    }
    a /= 2;
    b /= 2;
  }

  return (int)ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  offset = 1;
  while (offset < n) {
    offset *= 2;
  }

  for (int i = 0; i < n; ++i) tree[i + offset] = 1;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    Update(i, x);
  }
  
  for (int i = 0; i < m + k; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      // update
      b--;
      Update(b, c);
    } else {
      b--, c--;
      cout << Query(b, c) << "\n";
    }
  }

  return 0;
}