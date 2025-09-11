// Leaders (Bronze)
// https://www.acmicpc.net/problem/27561

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
char a[100005];
int e[100005];
int hl = -1, hr;
int gl = -1, gr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 'H') {
      if (hl == -1) hl = i;
      hr = i;
    } else if (a[i] == 'G') {
      if (gl == -1) gl = i;
      gr = i;
    }
  }

  int hh = -1, gg = -1;
  for (int s = 1; s <= n; ++s) {
    cin >> e[s];
    if (a[s] == 'H') {
      if (s == hl && hr <= e[s]) {
        hh = s;
      }
    } else {
      if (s == gl && gr <= e[s]) {
        gg = s;
      }
    }
  }

  int ans = 0;
  if (hh != -1 && gg != -1) ans++;
  if (hh != -1) { // gg == -1
    for (int i = 1; i < hh; ++i) {
      if (gg == i) continue;
      if (hh <= e[i]) ans++;
    }
  } 
  if (gg != -1) {
    for (int i = 1; i < gg; ++i) {
      if (hh == i) continue;
      if (gg <= e[i]) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}