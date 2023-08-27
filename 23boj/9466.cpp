// 텀 프로젝트
// https://www.acmicpc.net/problem/9466

#include <bits/stdc++.h>

using namespace std;

int visited[100010];
int nextt[100010];
long long seqs[100010];
long long seq;

int Dfs(int u) {
  int ret;

  if (visited[u] != -1) {
    // already visited
    if (seqs[u] < seq) {
      ret = 0;
    } else {
      if (visited[u] == u) {
        ret = u;
      }
    }
  } else {
    visited[u] = u;
    seqs[u] = seq;

    ret = Dfs(nextt[u]);
    if (ret == u) {
      ret = 0;
    } else {
      visited[u] = ret;
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  seq = 0;
  while (T--) {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
      visited[i] = -1;
      cin >> nextt[i];
    }

    for (int i = 1; i <= N; ++i) {
      if (visited[i] == -1) {
        Dfs(i);
        seq++;
      }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (visited[i] == 0) {
        ans++;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}