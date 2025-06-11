// 구간 합 구하기 3
// https://www.acmicpc.net/problem/11658

#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxLen = 1030;

int n, m;
int arr[kMaxLen][kMaxLen];
int trees[kMaxLen][kMaxLen];

int P(int k) { return k & -k; }

void Update(int x, int y, int d) {
  while (x <= n) {
    int idx = y;
    while (idx <= n) {
      trees[x][idx] += d;
      idx += P(idx);
    }
    x += P(x);
  }
}

int Sum(int x, int y) {
  int sum = 0;
  while (x >= 1) {
    int idx = y;
    while (idx >= 1) {
      sum += trees[x][idx];
      idx -= P(idx);
    }
    x -= P(x);
  }
  return sum;
}

int Query(int x1, int y1, int x2, int y2) {
  return Sum(x2, y2) - Sum(x1 - 1, y2) - Sum(x2, y1 - 1) + Sum(x1 - 1, y1 - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      Update(i, j, arr[i][j]);
    }
  }


  while (m--) {
    int w;
    cin >> w;
    if (w == 0) {
      int x, y, c;
      cin >> x >> y >> c;
      int d = c - arr[x][y];
      Update(x, y, d);
      arr[x][y] = c;
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << Query(x1, y1, x2, y2) << "\n";
    }
  }

  return 0;
}