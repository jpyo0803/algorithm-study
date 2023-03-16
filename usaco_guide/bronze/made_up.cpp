// Made Up (AC)
// https://atcoder.jp/contests/abc202/tasks/abc202_c?lang=en

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> A(N + 1), B(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; ++i) {
    cin >> B[i];
  }

  map<int, int> mm;
  for (int i = 0; i < N; ++i) {
    int c;
    cin >> c;
    mm[B[c]]++;
  }

  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += mm[A[i]];  // N(log(N)
  }

  cout << ans << "\n";
  return 0;
}