// Livestock Lineup
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<pair<string, string>> constraints(n);
  for (int i = 0; i < n; ++i) {
    string trash;
    cin >> constraints[i].first;
    for (int j = 0; j < 4; ++j) cin >> trash;
    cin >> constraints[i].second;
  }
  
  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  sort(cows.begin(), cows.end());
  
  do {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      string a, b;
      tie(a, b) = constraints[i];
      for (int j = 0; j < 8; ++j) {
        if (cows[j] == a) {
          bool left = false, right = false;
          if (j - 1 >= 0 && cows[j - 1] == b) left = true;
          if (j + 1 < 8 && cows[j + 1] == b) right = true;
          if (!left && !right) ok = false;
        }
      }
    }
    if (ok) break;
  } while (next_permutation(cows.begin(), cows.end()));

  for (const auto& cow: cows) {
    cout << cow << "\n";
  }

  return 0;
}