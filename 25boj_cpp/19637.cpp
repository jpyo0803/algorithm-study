// IF문 좀 대신 써줘
// https://www.acmicpc.net/problem/19637

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  vector<string> v1(n);
  vector<int> v2(n);
  for (int i = 0; i < n; ++i) {
    cin >> v1[i] >> v2[i];
  }

  for (int i = 0; i < m; ++i) {
    int power;
    cin >> power;

    auto it = lower_bound(v2.begin(), v2.end(), power);
    int idx = distance(v2.begin(), it);
    cout << v1[idx] << "\n";
  }

  return 0;
}