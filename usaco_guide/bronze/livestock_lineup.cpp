// Livestock Lineup (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  map<string, vector<string>> rels;
  for (int i = 0; i < N; ++i) {
    string a, b;
    cin >> a;
    for (int j = 0; j < 4; ++j) {
      cin >> b;
    }
    cin >> b;
    rels[a].push_back(b);
    rels[b].push_back(a);
  }

  for (auto& [k, v] : rels) {
    v.erase(unique(v.begin(), v.end()), v.end());
  }

  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                         "Bella",  "Blue",      "Betsy",   "Sue"};
  sort(cows.begin(), cows.end());

  do {
    bool ok = true;

    for (int i = 0; i < cows.size(); ++i) {
      for (auto& other : rels[cows[i]]) {
        int cnt = 0;
        if (i - 1 >= 0 && cows[i - 1] == other) {
          ++cnt;
        }
        if (i + 1 < cows.size() && cows[i + 1] == other) {
          ++cnt;
        }
        if (cnt == 0) {
          ok = false;
        }
        if (!ok) break;
      }
    }

    if (ok) break;
  } while (next_permutation(cows.begin(), cows.end()));

  for (auto& cow : cows) {
    cout << cow << "\n";
  }

  return 0;
}