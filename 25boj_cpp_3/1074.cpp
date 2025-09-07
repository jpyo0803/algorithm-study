// Z
// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, r, c;
int ans;

int Pow(int base, int exp) {
  if (exp == 0) return 1;
  int res = Pow(base, exp / 2);
  res *= res;
  if (exp % 2) res *= base;
  return res;
}

void Solve(int n, int x, int y, int ord) {
  if (n == 0) {
    if (x == r && y == c) {
      ans = ord;
    }
    return;
  }

  int s = Pow(2, n - 1);
  if (r >= x && r < x + s && c >= y && c < y + s)
    Solve(n - 1, x, y, ord);
  else if (r >= x && r < x + s && c >= y + s && c < y + s + s)
    Solve(n - 1, x, y + s, ord + s * s);
  else if (r >= x + s && r < x + s + s && c >= y && c < y + s)
    Solve(n - 1, x + s, y, ord + s * s * 2);
  else if (r >= x + s && r < x + s + s && c >= y + s && c < y + s + s)
    Solve(n - 1, x + s, y + s, ord + s * s * 3);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> r >> c;

  Solve(n, 0, 0, 0);

  cout << ans << "\n";

  return 0;
}