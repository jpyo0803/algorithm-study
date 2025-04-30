// 다각형의 면적
// https://www.acmicpc.net/problem/2166

/*
  Apply Shoelace formula
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<pair<int, int>> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  long long area = 0;
  for (int i = 0; i < n; ++i) {
    area += (long long)pts[i].first * pts[(i + 1) % n].second;
    area -= (long long)pts[i].second * pts[(i + 1) % n].first;
  }

  std::cout << std::fixed << std::setprecision(1) << fabs(area) / 2 << "\n";
  return 0;
}