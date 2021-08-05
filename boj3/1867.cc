//
// Stone Removal
// Link: https://www.acmicpc.net/problem/1867
//

#include <cstdio>

using namespace std;

constexpr int kMaxSize = 500;
int n, k, a, b;
bool adj[kMaxSize + 1][kMaxSize + 1];
int b_matched[kMaxSize + 1];
bool visited[kMaxSize + 1];

bool DFS(int a) {
  if (visited[a]) return false;
  visited[a] = true;

  for (int b = 1; b <= n; b++) {
    if (adj[a][b]) {
      if (b_matched[b] == -1 || DFS(b_matched[b])) {
        b_matched[b] = a;
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; i++) {
    b_matched[i] = -1;
  }

  for (int i = 0; i < k; i++) {
    scanf("%d%d", &a, &b);
    adj[a][b] = true;
  }

  int run_count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) visited[j] = false;
    if (DFS(i)) run_count += 1;
  }

  printf("%d\n", run_count);
  return 0;
}

