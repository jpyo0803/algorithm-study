//
// Book Handout
// Link: https:  // www.acmicpc.net/problem/9576
//

#include <array>
#include <cstdio>


constexpr int kMaxSize = 1000;
using namespace std;

int T, N, M, a, b;
bool visited[kMaxSize + 1];
int matched_to[kMaxSize + 1];
array<pair<int, int>, kMaxSize + 1> s_to_b;

bool DFS(int student) {
  if (visited[student]) return false;
  visited[student] = true;

  for (int book = s_to_b[student].first; book <= s_to_b[student].second; book++) {
    if (matched_to[book] == -1 || DFS(matched_to[book])) {
      matched_to[book] = student;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) matched_to[i] = -1;
    for (int i = 1; i <= M; i++) {
      scanf("%d%d", &a, &b);
      s_to_b[i].first = a;
      s_to_b[i].second = b;
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= M; j++) visited[j] = false;
      if (DFS(i)) ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}