//
// Representation of Set
// Link: https://www.acmicpc.net/problem/1717
//

#include <cstdio>

constexpr int kMaxSize = 1000000;
using namespace std;

int n, m, a, b, c;
int parent[kMaxSize + 1];

int count = 0;
int GetParent(int me) {
  if (parent[me] == me) return me;
  return parent[me] = GetParent(parent[me]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) parent[i] = i;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    int rb = GetParent(b);
    int rc = GetParent(c);
    if (a) {
      if (rb == rc)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      if (rb != rc) parent[rc] = rb;
    }
  }
  return 0;
}