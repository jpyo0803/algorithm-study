// 자원캐기
// https://www.acmicpc.net/problem/14430

#include <iostream>

using namespace std;

int cache[301][301];

int N, M, x;

int Max(int x, int y) { return x > y ? x : y; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> N >> M;
  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      cin >> x;
      cache[n][m] = Max(cache[n - 1][m], cache[n][m - 1]) + x;
    }
  }
  cout << cache[N][M] << endl;

  return 0;
}
