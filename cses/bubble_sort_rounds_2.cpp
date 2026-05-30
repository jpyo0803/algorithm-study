// Bubble Sort Rounds II
// https://cses.fi/problemset/task/3152/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  priority_queue<int> pq;
  for (int i = 0; i <= min(n - 1, k); ++i) {
    pq.push(-a[i]);
  }

  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = -pq.top();
    pq.pop();
    if (i + 1 + k < n) pq.push(-a[i + 1 + k]);
  }

  for (auto e : res) cout << e << " ";
  cout << "\n";

  return 0;
}