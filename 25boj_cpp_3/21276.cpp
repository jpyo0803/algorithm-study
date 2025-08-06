// 계보 복원가 호석
// https://www.acmicpc.net/problem/21276

#include <bits/stdc++.h>

using namespace std;

int n, m;

map<string, int> name2idx;
string idx2name[1005];

int indeg[1005];
vector<int> adj_list[1005];
int visited[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<string, set<string>> ans; 
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    ans[s] = set<string>();
    name2idx[s] = i;
    idx2name[i] = s;
    visited[i] = -1;
  }

  cin >> m;
  while (m--) {
    string sx, sy;
    cin >> sx >> sy;
    int x = name2idx[sx];
    int y = name2idx[sy];
    indeg[x]++;
    adj_list[y].push_back(x);
  }

  vector<string> rv;
  queue<pair<int, int>> que;
  for (int i = 1; i <= n; ++i) {
    if (indeg[i] == 0) {
      rv.push_back(idx2name[i]);
      que.push({i, 1});
      visited[i] = 1;
    }
  }


  while (que.size()) {
    int u, d;
    tie(u, d) = que.front();
    que.pop();

    for (auto& v : adj_list[u]) {
      if (visited[v] != -1) continue;
      indeg[v]--;
      if (indeg[v] == 0) {
        ans[idx2name[u]].insert(idx2name[v]);
        visited[v] = d + 1;
        que.push({v, d + 1});
      }
    }
  }

  sort(rv.begin(), rv.end());
  cout << rv.size() << "\n";
  for (auto& e : rv) cout << e << " ";
  cout << "\n";

  for (auto& e : ans) {
    cout << e.first << " " << e.second.size() << " ";
    for (auto& f : e.second) cout << f << " ";
    cout << "\n";
  }

  return 0;
}