// 킹 
// https://www.acmicpc.net/problem/1063

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool OutOfRange(int x, int y) { return x < 0 || x >= 8 || y < 0 || y >= 8; }

int kpx, kpy, spx, spy;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string ps;
  cin >> ps;
  kpx = ps[1] - '1', kpy = ps[0] - 'A';
  cin >> ps;
  spx = ps[1] - '1', spy = ps[0] - 'A';

  cin >> n;

  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "R") {
      if (OutOfRange(kpx, kpy + 1)) continue;
      if (kpx == spx && kpy + 1 == spy) {
        if (OutOfRange(spx, spy + 1)) continue;
        spy++;
      }
      kpy++;
    } else if (cmd == "L") {
      if (OutOfRange(kpx, kpy - 1)) continue;
      if (kpx == spx && kpy - 1 == spy) {
        if (OutOfRange(spx, spy - 1)) continue;
        spy--;
      }
      kpy--;
    } else if (cmd == "B") {
      if (OutOfRange(kpx - 1, kpy)) continue;
      if (kpx - 1 == spx && kpy == spy) {
        if (OutOfRange(spx - 1, spy)) continue;
        spx--;
      }
      kpx--;
    } else if (cmd == "T") {
      if (OutOfRange(kpx + 1, kpy)) continue;
      if (kpx + 1 == spx && kpy == spy) {
        if (OutOfRange(spx + 1, spy)) continue;
        spx++;
      }
      kpx++;
    } else if (cmd == "RT") {
      if (OutOfRange(kpx + 1, kpy + 1)) continue;
      if (kpx + 1 == spx && kpy + 1 == spy) {
        if (OutOfRange(spx + 1, spy + 1)) continue;
        spx++;
        spy++;
      }
      kpx++;
      kpy++;
    } else if (cmd == "LT") {
      if (OutOfRange(kpx + 1, kpy - 1)) continue;
      if (kpx + 1 == spx && kpy - 1 == spy) {
        if (OutOfRange(spx + 1, spy - 1)) continue;
        spx++;
        spy--;
      }
      kpx++;
      kpy--;
    } else if (cmd == "RB") {
      if (OutOfRange(kpx - 1, kpy + 1)) continue;
      if (kpx - 1 == spx && kpy + 1 == spy) {
        if (OutOfRange(spx - 1, spy + 1)) continue;
        spx--;
        spy++;
      }
      kpx--;
      kpy++;
    } else if (cmd == "LB") {
      if (OutOfRange(kpx - 1, kpy - 1)) continue;
      if (kpx - 1 == spx && kpy - 1 == spy) {
        if (OutOfRange(spx - 1, spy - 1)) continue;
        spx--;
        spy--;
      }
      kpx--;
      kpy--;
    }
  }

  cout << char(kpy + 'A') << char(kpx + '1') << "\n";
  cout << char(spy + 'A') << char(spx + '1') << "\n";

  return 0;
}