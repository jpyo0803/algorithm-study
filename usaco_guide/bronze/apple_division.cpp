// Apple Division
// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;

int N;
long long ans = 1e15;
long long sum = 0;

void Search(const vector<int>& apples, int k, long long b) {
  if (k == N) {
    long long a = sum - b;
    ans = min(ans, abs(a - b));
    return;
  }

  Search(apples, k + 1, b);
  Search(apples, k + 1, b + apples[k]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  vector<int> apples(N);
  for (int i = 0; i < N; ++i) {
    cin >> apples[i];
    sum += apples[i];
  }

  Search(apples, 0, 0);
  cout << ans << "\n";

  return 0;
}