//
// PICNIC
// Problem: https://www.algospot.com/judge/problem/read/PICNIC
//

#include <cstdio>

constexpr int kMaxStudent = 10;

using namespace std;

int C, n, m, a, b;
bool relationship[kMaxStudent][kMaxStudent];
bool taken[kMaxStudent];

int Solve() {
  int first_free = -1;
  for (int i = 0; i < n; i++) {
    if (!taken[i]) {
      first_free = i;
      break;
    }
  }

  if (first_free == -1) return 1;

  int ret = 0;
  for (int i = first_free + 1; i < n; i++) {
    if (!taken[i] && relationship[first_free][i]) {
      taken[i] = taken[first_free] = true;
      ret += Solve();
      taken[i] = taken[first_free] = false;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d%d", &n, &m);  // n = num students, m = num pair
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      relationship[a][b] = relationship[b][a] = true;
    }

    printf("%d\n", Solve());

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        relationship[i][j] = false;
      }
    }
  }
  return 0;
}