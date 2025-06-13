// Don't Be Last! (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> mm = {
    {"Bessie", 0},    {"Elsie", 0},  {"Daisy", 0},     {"Gertie", 0},
    {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name;
    int p;
    cin >> name >> p;
    mm[name] += p;
  }

  vector<pair<int, string>> vv;
  for (auto& e : mm) {
    vv.emplace_back(e.second, e.first);
  }

  sort(vv.begin(), vv.end());

  int val = vv[0].first;
  int idx = -1;
  for (int i = 1; i < vv.size(); ++i) {
    if (val != vv[i].first) {
      idx = i;
      break;
    }
  }

  if (idx == -1)
    cout << "Tie\n";
  else {
    int cnt = 0;
    for (int i = 0; i < vv.size(); ++i) {
      if (vv[idx].first == vv[i].first) cnt++;
    }
    if (cnt == 1) cout << vv[idx].second << "\n";
    else cout << "Tie\n";
  }

  return 0;
}