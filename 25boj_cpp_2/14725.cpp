// 개미굴
// https://www.acmicpc.net/problem/14725

#include <bits/stdc++.h>

using namespace std;

int n, k;

map<string, set<string>> adj_list;

void Solve(string curr_path, string curr, int depth) {
  if (curr != "root") {
    for (int i = 1; i < depth; ++i) cout << "--";
    cout << curr << "\n";
  }

  string next_path = curr_path + curr;
  for (const auto& next : adj_list[next_path]) {
    Solve(next_path, next, depth + 1);
  }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;

    string path = "root";
    for (int j = 1; j <= k; ++j) {
      string curr;
      cin >> curr;
      adj_list[path].insert(curr);
      path += curr;
    }
  }

  string path = "";
  string curr = "root";

  Solve(path, curr, 0);

  return 0;
}