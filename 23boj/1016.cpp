// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016

#include <bits/stdc++.h>

using namespace std;

bool chk[1000000];
bool chk2[1000010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long x, y;
  cin >> x >> y;

  vector<long long> pns;
  for (int i = 2; i < 1e6; ++i) {
    if (chk[i] == true) continue;
    int j = i;
    pns.push_back(i);
    while (j < 1e6) {
      chk[j] = true;
      j += i;
    }
  }

  for (auto e : pns) {
    auto e2 = e * e;

    long long j = x / e2;
    while (e2 * j <= y) {  // O(250000)
      if (e2 * j >= x) {
        chk2[e2 * j - x] = true;
      }
      j++;
    }
  }

  int ans = 0;
  for (int i = 0; i <= y - x; ++i) {
    if (chk2[i] == false) ans++;
  }

  cout << ans << "\n";

  return 0;
}