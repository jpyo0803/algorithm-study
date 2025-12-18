// Lifeguards (Silver)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int, int, bool>> vv;
  for (int i = 0; i < n; ++i) {
    int s, e;
    cin >> s >> e;
    vv.emplace_back(s, i, true);
    vv.emplace_back(e, i, false);
  }

  sort(vv.begin(), vv.end());

  set<int> active;
  vector<int> alone_time(n, 0);
  int total = 0;
  int prev = 0;

  for (auto e : vv) {
    int t, id;
    bool is_first;
    tie(t, id, is_first) = e;

    if (active.size()) total += t - prev;
    if (active.size() == 1) {
      alone_time[*active.begin()] += t - prev;
    }

    if (is_first) active.insert(id);
    else active.erase(id);

    prev = t;
  }

  int mi = 2e9;
  for (int i = 0; i < n; ++i) {
    mi = min(mi, alone_time[i]);
  }
  cout << total - mi << "\n";

  return 0;
}