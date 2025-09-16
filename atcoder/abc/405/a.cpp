// A - Is it rated? (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_a

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> x;

  bool ans = false;
  if (x == 1) {
    if (1600 <= r && r <= 2999) ans = true;
  } else {
    if (1200 <= r && r <= 2399) ans = true;
  } 
  cout << (ans ? "Yes" : "No") << "\n";

  return 0;
}