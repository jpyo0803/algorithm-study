// 치킨 배달 
// https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> hv, cv;
vector<int> chosen;

int Dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int Eval() {
  int ret = 0;
  for (auto h : hv) {
    int mi = 1e9;
    for (auto i : chosen) mi = min(mi, Dist(h, cv[i]));
    ret += mi;
  }
  return ret;
}


int Solve(int d, int start) {
  int ret = 1e9;
  if (d > 0) ret = Eval();
  if (d == m) return ret;
  if (start == cv.size()) return ret;

  for (int i = start; i < cv.size(); ++i) {
    chosen.push_back(i);
    ret = min(ret, Solve(d + 1, i + 1));
    chosen.pop_back();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      if (x == 1) hv.emplace_back(i, j);
      else if (x == 2) cv.emplace_back(i, j);
    }
  }

  cout << Solve(0, 0) << "\n";

  return 0;
}