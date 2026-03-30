// B. Ciel and Duel
// https://codeforces.com/contest/321/problem/B

#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
 
  vector<pair<int, int>> jv, cv;
  for (int i = 0; i < n; ++i) {
    string type;
    int str;
    cin >> type >> str;
    jv.emplace_back(type[0] == 'D', str); // D == 1, A == 0
  }
 
  for (int i = 0; i < m; ++i) {
    int str;
    cin >> str;
    cv.emplace_back(0, str);
  }

  sort(jv.begin(), jv.end());
  sort(cv.rbegin(), cv.rend());

  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < min(n, m); ++i) {
    if (jv[i].first == 0 && cv[i].second >= jv[i].second) {
      ans1 += cv[i].second - jv[i].second;
    } else {
      break;
    }
  }

  sort(jv.begin(), jv.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first > y.first; 
  });
  reverse(cv.begin(), cv.end());

  vector<bool> used(cv.size(), false);
  for (auto e : jv) {
    int type, str;
    tie(type, str) = e;

    bool found = false;
    for (int i = 0; i < cv.size(); ++i) {
      if (used[i]) continue;
      if (type == 0 && str <= cv[i].second || type == 1 && str < cv[i].second) {
        if (type == 0) ans2 += cv[i].second - str;
        used[i] = true;
        found = true;
        break;
      }
    }
    if (found == false) {
      cout << ans1 << "\n";
      return 0;
    }
  }

  for (int i = 0; i < cv.size(); ++i) {
    if (used[i] == false) {
      ans2 += cv[i].second;
    }
  }

  cout << max(ans1, ans2) << "\n";

  return 0;
}