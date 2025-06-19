// Milking Order (Bronze)
// https://www.acmicpc.net/problem/15764

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int h[105];

bool Check(vector<int> pos2cow, vector<int> cow2pos) {
  int i = 0; // position of a cow in the last hierarchy
  int hi = 0;
  while (hi < m) {
    if (cow2pos[h[hi]] == -1) {
      // cow at this hierarchy is not assigned yet
      while (i < n && pos2cow[i] != -1) i++; // find first empty spot
      pos2cow[i] = h[hi];
      cow2pos[h[hi]] = i;
      hi++;
    } else {
      // cow is already there
      if (i > cow2pos[h[hi]]) { // equal only happens at the very first access, and its valid
        return false;
      }

      i = cow2pos[h[hi]];
      hi++;
    }
  }

  // if you can successfully assign cows, then valid solution
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    cin >> h[i];
    h[i]--;
  }

  vector<int> cow2pos(n, -1);
  vector<int> pos2cow(n, -1);
  for (int i = 0; i < k; ++i) {
    int c, p;
    cin >> c >> p;
    if (c == 1) {
      cout << p << "\n";
      return 0;
    }
    c--, p--;
    cow2pos[c] = p;
    pos2cow[p] = c;
  }

  for (int i = 0; i < n; ++i) {
    if (pos2cow[i] == -1) {
      pos2cow[i] = 0; // try placing cow 1
      cow2pos[0] = i;
      if (Check(pos2cow, cow2pos)) {
        cout << i + 1 << "\n";
        return 0;
      }
      pos2cow[i] = -1;
      cow2pos[0] = -1;
    }
  }

  return 0;
}