//
// SORTGAME
// Problem: https://www.algospot.com/judge/problem/read/SORTGAME
//

#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int C, N;

map<vector<int>, int> op_count_map;

void Precalculation(int n) {
  vector<int> perm(n);
  for (int i = 0; i < n; i++) perm[i] = i;
  queue<vector<int>> que;
  que.push(perm);
  op_count_map[perm] = 0;

  while (!que.empty()) {
    vector<int> e = que.front();
    que.pop();
    int cost = op_count_map[e];
    for (int i = 0; i < n; i++) {
      for (int j = i + 2; j <= n; j++) {
        reverse(e.begin() + i, e.begin() + j);
        if (op_count_map.count(e) < 1) {
          que.push(e);
          op_count_map[e] = cost + 1;
        }
        reverse(e.begin() + i, e.begin() + j);
      }
    }
  }
}

int Solve(const vector<int>& vec) {
  int len = vec.size();
  vector<int> fixed(len);

  for (int i = 0; i < len; i++) {
    int smaller = 0;
    for (int j = 0; j < len; j++) {
      if (vec[j] < vec[i]) smaller++;
    }
    fixed[i] = smaller;
  }
  return op_count_map[fixed];
}

int main() {
  for (int i = 1; i <= 8; i++) Precalculation(i);
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d", &N);
    vector<int> seq(N);
    for (int n = 0; n < N; n++) {
      int e;
      scanf("%d", &e);
      seq[n] = e;
    }
    printf("%d\n", Solve(seq));
  }
  return 0;
}
