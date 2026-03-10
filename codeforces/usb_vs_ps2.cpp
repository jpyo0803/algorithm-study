// USB vs. PS/2
// https://codeforces.com/contest/762/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c, m;
  cin >> a >> b >> c >> m;

  vector<int> u, p;
  for (int i = 0; i < m; ++i) {
    int x;
    string s;
    cin >> x >> s;
    if (s[0] == 'U')
      u.push_back(x);
    else
      p.push_back(x);
  }

  sort(u.begin(), u.end());
  sort(p.begin(), p.end());

  int cnt = 0;
  ll tc = 0;
  for (int i = 0; i < min(a, (int)u.size()); ++i) tc += u[i], cnt++;
  for (int i = 0; i < min(b, (int)p.size()); ++i) tc += p[i], cnt++;

  int i = min(a, (int)u.size());
  int j = min(b, (int)p.size());
  while (i < u.size() && j < p.size() && c > 0) {
    if (u[i] < p[j]) {
      tc += u[i++];
    } else {
      tc += p[j++];
    }
    c--;
    cnt++;
  }

  while (c > 0 && i < u.size()) {
    tc += u[i++];
    cnt++;
    c--;
  }
  while (c > 0 && j < p.size()) {
    tc += p[j++];
    cnt++;
    c--;
  }

  cout << cnt << " " << tc << "\n";

  return 0;
}