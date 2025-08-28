// 스타트와 링크 
// https://www.acmicpc.net/problem/14889

#include <bits/stdc++.h>

using namespace std;

int n;
int s[20][20];

int Solve(vector<int>& a, int last) {
  int ret = 1e9;
  if (a.size() == n / 2) {
    bool is_a[20]{};
    for (auto e : a) is_a[e] = true;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      if (is_a[i]) continue;
      b.push_back(i);
    }

    ret = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
      for (int j = i + 1; j < a.size(); ++j) {
        ret += s[a[i]][a[j]] + s[a[j]][a[i]];
      }
    }
    for (int i = 0; i < b.size() - 1; ++i) {
      for (int j = i + 1; j < b.size(); ++j) {
        ret -= s[b[i]][b[j]] + s[b[j]][b[i]];
      }
    }
    return abs(ret);
  }

  for (int i = last + 1; i < n; ++i) {
    a.push_back(i);
    ret = min(ret, Solve(a, i));
    a.pop_back();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> s[i][j];
    }
  }

  vector<int> a;
  cout << Solve(a, -1) << "\n";

  return 0;
}