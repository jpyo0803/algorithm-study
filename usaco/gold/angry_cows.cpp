// Angry Cows (Gold)
// https://www.acmicpc.net/problem/11982

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

int UpperBound(const vector<int>& v, int x) {
  int lo = 0, hi = v.size();
  while (lo < hi) {
    int m = (lo + hi) / 2;
    if (v[m] <= x) {
      lo = m + 1;
    } else {
      hi = m;
    }
  }
  return lo;
}

bool CheckLeft(const vector<int>& v, int r, int idx, int pos) {
  if (idx <= 0) return idx < 0 || pos - r <= v[0];
  int next_idx = idx;
  while (next_idx >= 0 && v[next_idx] >= pos - r) next_idx--;
  if (idx == next_idx) return false;
  return CheckLeft(v, r - 2, next_idx, v[next_idx + 1]);
}

bool CheckRight(const vector<int>& v, int r, int idx, int pos) {
  if (idx >= n - 1) return idx >= n || v[n - 1] <= pos + r;
  int next_idx = idx;
  while (next_idx < n && v[next_idx] <= pos + r) next_idx++;
  if (idx == next_idx) return false;
  return CheckRight(v, r - 2, next_idx, v[next_idx - 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (auto& e : v) {
    cin >> e;
    e *= 2;
  }
  sort(v.begin(), v.end());

  int rlo = 0, rhi = 2e9;
  while (rlo <= rhi) {
    int r = rlo + (rhi - rlo) / 2;
    // cout << "r: " << r << endl;

    int poslo = 0, poshi = 2e9;
    while (poslo <= poshi) {
      int pos = poslo + (poshi - poslo) / 2;
      int idx = UpperBound(v, pos - 1);
      if (idx < n && CheckLeft(v, r, idx, pos)) {
        // cout << "S: pos lo / hi: " << poslo << " / " << poshi << endl;
        poslo = pos + 1;
      } else {
        // cout << "F: pos lo / hi: " << poslo << " / " << poshi << endl;
        poshi = pos - 1;
      }
    }

    int idx = UpperBound(v, poshi);
    if (CheckRight(v, r, idx, poshi)) {
      rhi = r - 1;
    } else {
      rlo = r + 1;
    }
  }

  cout << fixed << setprecision(1) << (double)rlo / 2.0 << "\n";

  return 0;
}