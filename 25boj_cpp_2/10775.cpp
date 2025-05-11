// 공항 
// https://www.acmicpc.net/problem/10775

#include <bits/stdc++.h>

using namespace std;

int G, P;

int p[100005];

int UF(int x) {
  if (p[x] == x) return x;
  return p[x] = UF(p[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> G;
  cin >> P;

  for (int i = 0; i <= G; ++i) {
    p[i] = i;
  }

  int ans = 0;
  for (int i = 0; i < P; ++i) {
    int g;
    cin >> g;
    
    int r = UF(g);
    if (r == 0) {
      break;
    }

    p[r] = r - 1;
    ans++;
  }

  cout << ans << "\n";

  return 0;
}