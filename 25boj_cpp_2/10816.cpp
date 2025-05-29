// 숫자 카드 2
// https://www.acmicpc.net/problem/10816

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  cin >> m;
  while (m--){
    int x;
    cin >> x;
    auto lit = lower_bound(v.begin(), v.end(), x);
    auto uit = upper_bound(v.begin(), v.end(), x);
    cout << uit - lit << " ";
  }

  return 0;
}