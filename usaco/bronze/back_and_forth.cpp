// Back and Forth (Bronze)
// https://www.acmicpc.net/problem/16771

#include <bits/stdc++.h>

using namespace std;

multiset<int> buckets[2];
int a_tank = 1000;
bool readings[2000];
int x;
int ans;

void Solve(int depth) {
  if (depth == 4) {
    if (readings[a_tank] == false) {
      ans++;
      readings[a_tank] = true;
    }
    return;
  }

  bool is_a2b = depth % 2 ? false : true;
  auto& from_buckets = is_a2b ? buckets[0] : buckets[1];
  auto& to_buckets = is_a2b ? buckets[1] : buckets[0];

  vector<int> cands;
  for (auto& e : from_buckets) cands.push_back(e);

  for (auto& e : cands) {
    int amt = is_a2b ? -e : e;
    a_tank += amt;
    to_buckets.insert(e);
    from_buckets.erase(from_buckets.find(e));
    Solve(depth + 1);
    from_buckets.insert(e);
    to_buckets.erase(to_buckets.find(e));
    a_tank -= amt;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> x;
      buckets[i].insert(x);
    }
  }

  Solve(0);

  cout << ans << "\n";

  return 0;
}