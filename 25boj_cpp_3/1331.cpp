// 나이트 투어
// https://www.acmicpc.net/problem/1331

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool vis[6][6];

pair<int, int> F(const string& s) { return {s[1] - '1', s[0] - 'A'}; }
bool CheckMove(pair<int, int> x, pair<int, int> y) {
  int dx = abs(x.first - y.first);
  int dy = abs(x.second - y.second);
  return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  pair<int, int> start = F(s);

  auto curr = start;
  bool ok = true;

  int cnt = 35;
  vis[curr.first][curr.second] = true;
  for (int i = 0; i < 35; ++i) {
    cin >> s;
    auto next = F(s);
    if (CheckMove(curr, next) == false) {
      ok = false;
      break;
    }
    if (vis[next.first][next.second]) {
      ok = false;
      break;
    }

    vis[next.first][next.second] = true;
    cnt--;
    curr = next;
  }

  if (CheckMove(start, curr) == false || cnt != 0) ok = false;

  cout << (ok ? "Valid" : "Invalid") << "\n";

  return 0;
}