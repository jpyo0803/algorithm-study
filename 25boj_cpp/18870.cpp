// 좌표 압축 
// https://www.acmicpc.net/problem/18870

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  vector<int> vv2 = vv;
  sort(vv2.begin(), vv2.end());

  vv2.erase(unique(vv2.begin(), vv2.end()), vv2.end());

  for (auto e : vv) {
    cout << (lower_bound(vv2.begin(), vv2.end(), e) - vv2.begin()) << " ";
  }
  cout << "\n";

  return 0;
}