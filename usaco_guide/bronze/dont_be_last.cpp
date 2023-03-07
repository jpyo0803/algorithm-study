// Don't Be Last (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=687

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<string, int> prod = {{"Bessie", 0},   {"Elsie", 0},     {"Daisy", 0},
                           {"Gertie", 0},   {"Annabelle", 0}, {"Maggie", 0},
                           {"Henrietta", 0}};

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    string a;
    int b;
    cin >> a >> b;
    prod[a] += b;
  }

  multiset<int> rank;
  for (auto& [x, y] : prod) {
    rank.insert(y);
  }

  int min_val = *rank.begin();
  if (rank.count(min_val) == rank.size()) {
    cout << "Tie\n";
  } else {
    int second_min_val = *rank.upper_bound(min_val);
    if (rank.count(second_min_val) > 1) {
      cout << "Tie\n";
    } else {
      for (auto& [name, amt] : prod) {
        if (amt == second_min_val) {
          cout << name << "\n";
        }
      }
    }
  }

  return 0;
}