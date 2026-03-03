// Meetings (Silver)
// https://www.acmicpc.net/problem/18266

#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Cow {
  int w, x, d;
  Cow() {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, l;
  cin >> n >> l;

  int W = 0;

  vector<Cow> cv(n);
  for (int i = 0; i < n; ++i) {
    cin >> cv[i].w >> cv[i].x >> cv[i].d;
    W += cv[i].w;
  }
  
  sort(cv.begin(), cv.end(), [](const Cow & a, const Cow& b) {
    return a.x < b.x;
  });

  vector<pair<int, int>> twv;
  vector<int> lv, rv;
  for (auto& c : cv) {
    if (c.d == 1) rv.push_back(c.x);
    else lv.push_back(c.x);
  }

  for (int i = 0; i < lv.size(); ++i) {
    twv.emplace_back(lv[i], cv[i].w);
  }
  for (int i = 0; i < rv.size(); ++i) {
    twv.emplace_back(l - rv[i], cv[lv.size() + i].w);
  }

  sort(twv.begin(), twv.end());

  int et;
  int wum = 0;
  for (auto& e : twv) {
    wum += e.second;
    if (wum * 2 >= W) {
      et = e.first;
      break;
    }
  }

  queue<int> que;
  int ans = 0;
  for (auto& e : cv) {
    int x = e.x, d = e.d;
    if (d == 1) {
      que.push(x);
    } else {
      while (que.size() && que.front() + 2 * et < x) {
        que.pop();
      }
      ans += que.size();
    }
  }
  cout << ans << "\n";

  return 0;
}