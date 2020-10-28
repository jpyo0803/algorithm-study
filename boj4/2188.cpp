//
// 축사 배정
// Link: https://www.acmicpc.net/problem/2188
//

#include <cstdio>
#include <vector>

constexpr int kMax = 200;
int N, M, a, b;
using namespace std;

vector<int> prefs[kMax + 1];
int matched_to[kMax + 1];
bool visited[kMax + 1];

bool DFS(int cow) {
  if (visited[cow]) return false;
  visited[cow] = true;

  for (auto& pref : prefs[cow]) {
    if (matched_to[pref] == -1 || DFS(matched_to[pref])) {
      matched_to[pref] = cow;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) matched_to[i] = -1;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &a);
    for (int j = 0; j < a; j++) {
      scanf("%d", &b);
      prefs[i].push_back(b);
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int i = 1; i <= N; i++) visited[i] = false;
    if (DFS(i)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}