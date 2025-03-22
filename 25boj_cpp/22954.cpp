// 그래프 트리 분할 
// https://www.acmicpc.net/problem/22954

/*
  1. Trees must be different in sizes
  2. Connectivity를 확인해 3개 이상으로 나누어져있으면 -1
  3. Conn. 확인해 2개로 나누어져있으면 그대로 출력
  4. 하나로 연결된 그래프인 경우, 간선을 제거해 하나의 트리로 만들고 적절하게 간선을 하나더 제거해 
  크기가 다른 두개의 트리를 만든다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int p[100010];

vector<pair<int, int>> adj_list[100010];
bool visited[100010];

int disable_u = -1, disable_v;

int UF(int x) {
  if (p[x] == x) return x;
  p[x] = UF(p[x]);
  return p[x];
}

void Dfs(int u, vector<int>& vv, vector<int>& ev) {
  visited[u] = true;
  vv.push_back(u);

  for (auto x : adj_list[u]) {
    int v = x.first;
    if (disable_u != -1 && min(disable_u, disable_v) == min(u, v) && max(disable_u, disable_v) == max(u, v)) continue;
    if (visited[v] == false) {
      ev.push_back(x.second);
      Dfs(v, vv, ev);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  // n1 + n2 == n
  // m1 == n1 - 1, m2 == n2 - 1, m1 + m2 + 2 == n
  // m1 + m2 == m
  if (n <= 2 || m + 2 < n) {
    cout << "-1\n";
    return 0;
  }

  // n >= 3, m >= n - 2

  for (int i = 1; i <= n; ++i) p[i] = i;

  vector<pair<int, int>> ev(m + 10);
  for (int i = 1; i <= m; ++i) { 
    cin >> ev[i].first >> ev[i].second;
  }

  int edge_cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int u = ev[i].first;
    int v = ev[i].second;

    int a = UF(u);
    int b = UF(v);
    
    if (a != b) {
      adj_list[u].emplace_back(v, i);
      adj_list[v].emplace_back(u, i);
      
      p[a] = b;
      edge_cnt++;
      if (edge_cnt == n - 1) break;
    }
  }

  if (edge_cnt < n - 2) {
    cout << "-1\n";
    return 0;
  } else if (edge_cnt == n - 1) {
    // disconnect a vertex with one edge
    for (int i = 1; i <= n; ++i) {
      if (adj_list[i].size() == 1) {
        disable_u = i;
        disable_v = adj_list[i].front().first;
        break;
      }
    }
  }

  vector<int> vv1, vv2, ev1, ev2;

  for (int i = 1; i <= n; ++i) {
    if (visited[i] == false) {
      // cout << "start " << i << endl;
      Dfs(i, (vv1.size() ? vv2 : vv1), (vv1.size() ? ev2 : ev1));
    }
  }

  if (vv1.size() == vv2.size()) {
    cout << "-1\n";
    return 0;
  }

  cout << vv1.size() << " " << vv2.size() << "\n";
  for (auto e : vv1) cout << e << " ";
  cout << "\n";
  for (auto e : ev1) cout << e << " ";
  cout << "\n";
  for (auto e : vv2) cout << e << " ";
  cout << "\n";
  for (auto e : ev2) cout << e << " ";
  cout << "\n";

  return 0;
}