// Apple Division
// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[20];

long long Solve(long long sum1, long long sum2, int depth) {
  if (depth == n) {
    return abs(sum1 - sum2); 
  }

  return min(Solve(sum1 + arr[depth], sum2, depth + 1), Solve(sum1, sum2 + arr[depth], depth + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << Solve(0, 0, 0) << "\n";

  return 0;
}