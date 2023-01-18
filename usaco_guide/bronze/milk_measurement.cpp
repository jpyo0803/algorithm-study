// Milk Measurement
// http://www.usaco.org/index.php?page=viewproblem2&cpid=761

#include <bits/stdc++.h>

using namespace std;

int N;

struct Measure {
  int day, delta;
  string name;

  Measure(int _day, string _name, int _delta)
      : day(_day), name(_name), delta(_delta) {}

  bool operator<(const Measure& other) { return day < other.day; }
};

int Name2Idx(const string& name) {
  if (name[0] == 'B')
    return 0;
  else if (name[0] == 'E')
    return 1;
  return 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  vector<Measure> measures;

  for (int i = 0; i < N; ++i) {
    int day, delta;
    string name;
    cin >> day >> name >> delta;
    measures.emplace_back(day, name, delta);
  }

  sort(measures.begin(), measures.end());

  set<string> last, now;
  last.insert("Bessie");
  last.insert("Elsie");
  last.insert("Mildred");

  int amt[3] = {0, 0, 0};

  int ans = 0;

  for (auto& measure : measures) {
    amt[Name2Idx(measure.name)] += measure.delta;

    vector<pair<int, string>> v = {
        {amt[0], "Bessie"}, {amt[1], "Elsie"}, {amt[2], "Mildred"}};
    sort(v.rbegin(), v.rend());

    now.insert(v[0].second);
    if (v[0].first == v[1].first) now.insert(v[1].second);
    if (v[0].first == v[2].first) now.insert(v[2].second);

    if (last != now) {
      ++ans;
      swap(last, now);
    }
    now.clear();
  }

  cout << ans << "\n";

  return 0;
}