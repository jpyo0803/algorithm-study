// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549

#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[100010];

long long Solve(int l, int r) {
  if (l == r) return arr[l];

  int mid = (l + r) / 2;
  long long a = Solve(l, mid);
  long long b = Solve(mid + 1, r);

  long long c;
  int lp, rp;
  lp = mid;
  rp = mid + 1;
  int len = 2;
  long long curr_min = min(arr[lp], arr[rp]);
  c = curr_min * len;

  // only search [l, r] including mid, mid + 1
  while (lp > l && rp < r) {
    len++;
    long long left_cand = min(arr[lp - 1], curr_min) * len;
    long long right_cand = min(arr[rp + 1], curr_min) * len;

    if (left_cand > right_cand) {
      lp--;
      c = max(c, left_cand);
      curr_min = min(curr_min, arr[lp]);
    } else {
      rp++;
      c = max(c, right_cand);
      curr_min = min(curr_min, arr[rp]);
    }
  }

  while (rp < r) {
    // rp still to go
    len++;
    long long right_cand = min(arr[rp + 1], curr_min) * len;
    rp++;
    curr_min = min(curr_min, arr[rp]);
    c = max(right_cand, c);
  }
  while (lp > l) {
    len++;
    long long left_cand = min(arr[lp - 1], curr_min) * len;
    lp--;
    curr_min = min(curr_min, arr[lp]);
    c = max(left_cand, c);
  }

  return max(c, max(a, b));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    cin >> n;
    if (n == 0) break;

    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << Solve(0, n - 1) << "\n";
  }

  return 0;
}