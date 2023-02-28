// Apple Division
// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  long long sum = 0;

  vector<int> apples(N);
  for (int i = 0; i < N; ++i) {
    cin >> apples[i];
    sum += apples[i];
  }

  long long ans = 1e15;

  for (int i = 0; i < (1 << N); ++i) {
    long long b = 0;
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        b += apples[j];
      }
    }
    long long a = sum - b;
    ans = min(ans, abs(a - b));
  }

  cout << ans << "\n";

  return 0;
}