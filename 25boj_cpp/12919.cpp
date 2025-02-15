// A와 B 2
// https://www.acmicpc.net/problem/12919

#include <bits/stdc++.h>

using namespace std;

string s, t;

char buf[55];
bool ans = false;

void Solve(int l, int r, bool flipped) {
  if (r - l + 1 == s.length()) {
    int j = flipped ? r : l;

    bool match = true;
    for (auto ch : s) {
      if (ch != buf[j]) {
        match = false;
        break;
      }
      if (flipped) j--;
      else j++;
    }
    ans |= match;
    return;
  }

  if (flipped) {
    if (buf[r] == 'B') Solve(l, r - 1, !flipped);
    if (buf[l] == 'A') Solve(l + 1, r, flipped);
  } else {
    if (buf[r] == 'A') Solve(l, r - 1, flipped);
    if (buf[l] == 'B') Solve(l + 1, r, !flipped);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s >> t;

  for (int i = 0; i < t.length(); ++i) buf[i] = t[i];

  Solve(0, t.length() - 1, false);

  cout << ans << "\n";

  return 0;
}