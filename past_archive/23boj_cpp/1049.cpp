// 기타줄
// https://www.acmicpc.net/problem/1049

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> c;

  int min_pack = 1e9;
  int min_unit = 1e9;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    c.emplace_back(a, b);
    if (a < min_pack) {
      min_pack = a;
    }
    if (b < min_unit) {
      min_unit = b;
    }
  }

  int r = N % 6;
  int q = N / 6;

  int all_pack = q * min_pack;
  if (r > 0) {
    all_pack += min_pack;
  }

  int all_unit = N * min_unit;
  int hybrid = q * min_pack + r * min_unit;
  int ans = min({all_pack, all_unit, hybrid});
  // min (all 낱개, all 패키지, 합성)

  cout << ans << "\n";

  return 0;
}