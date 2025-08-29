// 톱니바퀴
// https://www.acmicpc.net/problem/14891

#include <bits/stdc++.h>

using namespace std;

int k;

struct Gear {
  int x;
  Gear() {
    x = 0;
    for (int i = 0; i < 8; ++i) {
      char ch;
      cin >> ch;
      x <<= 1;
      x |= (ch == '1') ? 1 : 0;
    }
  }

  void CW() {
    x |= (x & 1) << 8;
    x >>= 1;
    x &= (1 << 8) - 1;
  }

  void CCW() {
    x <<= 1;
    x |= (x >> 8) & 1;
    x &= (1 << 8) - 1;
  }

  int Right() const {
    return (x >> 5) & 1;
  }

  int Left() const {
    return (x >> 1) & 1;
  }

  int Top() const {
    return (x >> 7) & 1;
  }
};

vector<Gear> gv;

void Solve(int pos, int dir, int prev) {
  bool lok = false, rok = false;
  if (pos - 1 >= 0 && prev != pos - 1 && gv[pos].Left() != gv[pos - 1].Right()) lok = true;
  if (pos + 1 < 4 && prev != pos + 1 && gv[pos].Right() != gv[pos + 1].Left()) rok = true;

  dir == 1 ? gv[pos].CW() : gv[pos].CCW();

  if (lok) Solve(pos - 1, -dir, pos);
  if (rok) Solve(pos + 1, -dir, pos);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 4; ++i) gv.emplace_back();

  cin >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--;
    Solve(x, y, -1);
  }

  int f = 1;
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    if (gv[i].Top()) ans += f;
    f *= 2;
  }
  cout << ans << "\n";

  return 0;
}