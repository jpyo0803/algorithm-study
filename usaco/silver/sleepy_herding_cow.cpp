// Sleepy Cow Herding (Silver)
// https://www.acmicpc.net/problem/17036

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int FindMin(vector<int> v) {
  int n = v.size();

  int l = 0;
  int ret = 1e9;
  // 4 7 9
  for (int r = 0; r < n; ++r) {
    if (v[r] < n) continue;
    while (v[r] - v[l] + 1 > n) l++;
    if (r - l + 1 == n - 1 && v[r] - (n - 1) + 1 == v[l]) continue;
    ret = min(ret, n - (r - l + 1));
  }
  return ret;
}
int FindMax(vector<int> v) {
  int n = v.size();
  // n - 1개 원소를 포함하는 가장 넓은 구간에서 n - 1 을뺌
  return max(v[n - 2] - v[0] + 1, v[n - 1] - v[1] + 1) - (n - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  int a = FindMin(v);
  for (auto& e : v) e = -e;
  reverse(v.begin(), v.end());
  cout << min(a, FindMin(v)) << "\n";
  cout << FindMax(v) << "\n";

  return 0;
}