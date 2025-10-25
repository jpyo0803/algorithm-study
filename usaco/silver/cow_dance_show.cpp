// Cow Dance Show (Silver)
// https://www.acmicpc.net/problem/14452

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, t;
int darr[10005];

bool F(int k) {
  priority_queue<int> pq; // stores finish time
  int tt = 0;
  int i = 0;
  while (i < n) {
    if (pq.size() < k) {
      pq.push(-(tt + darr[i]));
      i++;
    } else {
      tt = -pq.top();
      pq.pop();
    }
  }
  while (pq.size()) {
    tt = -pq.top();
    pq.pop();
  }
  return tt <= t;
}

int LastTrue(int lo, int hi) {
  hi++;
  for (int dif = hi - lo; dif > 0; dif /= 2) {
    while (hi - dif >= lo && F(hi - dif)) hi -= dif;
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> t;
  for (int i = 0; i < n; ++i) cin >> darr[i];

  cout << LastTrue(1, n) << "\n";

  return 0;
}