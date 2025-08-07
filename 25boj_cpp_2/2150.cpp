// Strongly Connected Component
// https://www.acmicpc.net/problem/2150

#include <bits/stdc++.h>

using namespace std;

int v, e;

bool visited[10005];
int num_components = 0;
vector<int> components[10005];

vector<int> adj_list[10005];
vector<int> adj_list_rev[10005];

stack<int> stk;

void Dfs1(int x) {
  visited[x] = true;
  for (auto y : adj_list[x]) {
    if (visited[y]) continue;
    Dfs1(y);
  }
  stk.push(x);
}

void Dfs2(int x) {
  visited[x] = true;

  components[num_components].push_back(x);
  for (auto y : adj_list_rev[x]) {
    if (visited[y]) continue;
    Dfs2(y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list_rev[b].push_back(a);
  }

  for (int i = 1; i <= v; ++i) {
    if (visited[i] == false) {
      Dfs1(i);
    }
  }

  for (int i = 1; i <= v; ++i) visited[i] = false;

  while (stk.empty() == false) {
    auto x = stk.top();
    stk.pop();

    if (visited[x] == false) {
      Dfs2(x);
      num_components++;
    }
  }

  vector<pair<int, int>> ord(num_components);
  for (int i = 0; i < num_components; ++i) {
    sort(components[i].begin(), components[i].end());
    ord[i].first = components[i].front();
    ord[i].second = i;
  }
  sort(ord.begin(), ord.end());

  cout << num_components << "\n";
  for (int i = 0; i < num_components; ++i) {
    for (auto e : components[ord[i].second]) {
      cout << e << " ";
    }
    cout << "-1\n";
  }

  return 0;
}