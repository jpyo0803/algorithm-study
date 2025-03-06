// 전구와 스위치
// https://www.acmicpc.net/problem/2138

#include <bits/stdc++.h>

using namespace std;

int n;

void PrintArr(const vector<bool>& in) {
  for (auto e : in) cout << (e ? '1' : '0');
  cout << endl;
}

int Solve(vector<bool>& in, const vector<bool>& ref) {
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (in[i - 1] != ref[i - 1]) {
      for (int j = -1; j <= 1; ++j) {
        int idx = i + j;
        if (idx < 0 || idx >= n) continue;
        in[idx] = !in[idx];
      }
      cnt++;
    }
    // PrintArr(in);
  }

  if (in != ref) cnt = -1;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  string ss;
  cin >> ss;

  vector<bool> a(n);
  for (int i = 0; i < n; ++i) a[i] = ss[i] == '0' ? false : true;

  cin >> ss;
  vector<bool> ref(n);
  for (int i = 0; i < n; ++i) ref[i] = ss[i] == '0' ? false : true;

  int ans = 1e9;
  int cand;

  auto x = a;
  x[0] = !x[0];
  x[1] = !x[1];
  cand = Solve(x, ref);
  if (cand != -1) ans = min(ans, cand + 1);

  auto y = a;
  cand = Solve(y, ref);
  if (cand != -1) ans = min(ans, cand);

  if (ans == 1e9) ans = -1;

  cout << ans << "\n";

  return 0;
}