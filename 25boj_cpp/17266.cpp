// 어두운 굴다리
// https://www.acmicpc.net/problem/17266

#include <bits/stdc++.h>

using namespace std;

int n, m;
int pos[100010];

bool coverage_check(int h) {
  int range_left, range_right;
  for (int i = 0; i < m; ++i) {
    int l = pos[i] - h;
    int r = pos[i] + h;
    if (i == 0) {
      if (l > 0) return false;
      range_left = l;
      range_right = r;
    } else {
      if (range_right < l) return false; // gap
      range_right = r;
    }
  }
  return range_right >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> pos[i];

  int hl = 0;
  int hr = n;

  int ans;
  int cnt = 0;
  while (hl <= hr) {
    int h = (hl + hr) / 2;
    bool res = coverage_check(h);
    if (res) {
      hr = h - 1;
      ans = h;
    } else {
      hl = h + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}