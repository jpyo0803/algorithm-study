// Modern Art (Bronze)
// https://www.acmicpc.net/problem/14532

#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int lx = 12, ly = 12, hx = -1, hy = -1;
  bool valid = false;
};

int n;
Rect rects[10];
char board[12][12];

bool IsCover(int a, int b) {
  /* 
    if no overlab, return false
    overlap 하는 부분이 있다면 겹치는 부분을 확인해 a가 하나라도 있다면 return true
  */
  Rect c;
  c.lx = max(rects[a].lx, rects[b].lx);
  c.ly = max(rects[a].ly, rects[b].ly);
  c.hx = min(rects[a].hx, rects[b].hx);
  c.hy = min(rects[a].hy, rects[b].hy);

  if (c.lx > c.hx || c.ly > c.hy) return false; // no overlap

  bool is_cover = false;
  for (int i = c.lx; i <= c.hx; ++i) {
    for (int j = c.ly; j <= c.hy; ++j) {
      if (board[i][j] - '0' == a) {
        is_cover = true;
      }
    }
  }
  return is_cover;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      int color = board[i][j] - '0';
      if (color == 0) continue;
      rects[color].lx = min(rects[color].lx, i);
      rects[color].ly = min(rects[color].ly, j);
      rects[color].hx = max(rects[color].hx, i);
      rects[color].hy = max(rects[color].hy, j);
      rects[color].valid = true;
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= 9; ++i) {
    if (rects[i].valid == false) continue;
    bool is_cover = false;
    for (int j = 1; j <= 9; ++j) {
      if (i == j || rects[j].valid == false) continue;
      is_cover |= IsCover(i, j);
    } 
    if (is_cover == false) ans++;
  }

  cout << ans << "\n";

  return 0;
}