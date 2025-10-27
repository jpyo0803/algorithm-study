// Convention (Silver)
// https://www.acmicpc.net/problem/16766

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, c;
int a[100005];

bool F(int w) {
  int bus_cnt = 0;
  int seat_cnt = 0;
  int start_time = 0;
  bool restart = true;

  int i = 0;
  while (i < n) {
    if (restart) {
      start_time = a[i];
      seat_cnt = 1;
      bus_cnt++;
      i++;
      restart = false;
    } else {
      if (seat_cnt < c && start_time + w >= a[i]) {
        seat_cnt++;
        i++;
      } else {
        restart = true;
      }
    }
  }
  return bus_cnt <= m;
}

int Solve(int lo, int hi) {
  hi++;
  while (lo < hi) {
    int mid = lo + (hi - 1 - lo) / 2;
    if (F(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> c;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);

  cout << Solve(0, 1e9) << "\n";

  return 0;
}