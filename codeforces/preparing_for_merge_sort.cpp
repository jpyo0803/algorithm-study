// Preparing for Merge Sort
// https://codeforces.com/contest/847/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int F(const vector<int>& v, int x) {
  if (v.empty()) return -1;

  int lo = 0, hi = v.size();

  while (lo < hi) {
    int mid = lo + (hi - 1 - lo) / 2;
    if (v[mid] < x) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return (hi == v.size() ? -1 : hi); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> ans;
  vector<int> lv;  // keeps last element of
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    int pos = F(lv, a);
    if (pos != -1) {
      ans[pos].push_back(a);
      lv[pos] = a;
    } else {
      ans.push_back({a});
      lv.push_back(a);
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}