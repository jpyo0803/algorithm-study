// Livestock Lineup (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int n;

map<string, vector<string>> adj_list;
set<string> ss = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                  "Bella",  "Blue",      "Betsy",   "Sue"};

void Dfs(vector<string>& chain, const string& u) {
  chain.push_back(u);
  ss.erase(ss.find(u));
  for (const auto& v : adj_list[u]) {
    if (ss.find(v) == ss.end()) continue;
    Dfs(chain, v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string a, b, trash;
    cin >> a;
    for (int j = 0; j < 4; ++j) cin >> trash;
    cin >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  vector<string> vv;
  for (auto& e : ss) vv.push_back(e);

  vector<vector<string>> ans;
  for (auto& key : vv) {
    if (ss.find(key) == ss.end()) continue;
    int sz = adj_list[key].size();
    if (sz == 2) continue;
    vector<string> chain;
    Dfs(chain, key);
    ans.push_back(chain);
  }

  sort(ans.begin(), ans.end(),
       [](const vector<string>& v1, const vector<string>& v2) {
         return v1[0] < v2[0];
       });

  for (auto& v : ans) {
    for (auto& e : v) {
      cout << e << "\n";
    }
  }

  return 0;
}