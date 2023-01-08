//
// Bipartite Graph
// Problem: https://www.acmicpc.net/problem/1707
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX{20000};
int T, V, E, a, b;

vector<int> adj_list[MAX + 1];
bool visited[MAX + 1];
bool color[MAX + 1];

bool ans;
void dfs(int u, bool prev_color) {
  visited[u] = true;
  color[u] = !prev_color;

  for (auto v : adj_list[u]) {
    if (!visited[v]) {  // not visited
      dfs(v, !prev_color);
    } else {
      if (color[v] == !prev_color) {
        ans = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> V >> E;

    ans = true;
    for (int i = 1; i <= V; i++) {
      adj_list[i].clear();
      visited[i] = false;
    }

    for (int i = 0; i < E; i++) {
      cin >> a >> b;
      adj_list[a].push_back(b);
      adj_list[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
      if (!visited[i]) {
        dfs(i, false);
      }
    }

    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}