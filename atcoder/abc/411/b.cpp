// B - Distance Table (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_b

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> dist(n - 1);
  for (int i = 0; i < n - 1; ++i) cin >> dist[i];

  for (int i = 0; i < n - 1; ++i) {
    int sum = 0;
    for (int j = i; j < n - 1; ++j) {
      sum += dist[j];
      cout << sum << " ";
    }
    cout << "\n";
  }

  return 0;
}