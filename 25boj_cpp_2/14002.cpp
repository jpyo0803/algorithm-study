// 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002

#include <bits/stdc++.h>

using namespace std;

int p[1005];
int arr[1005];
int dp[1005];

int n;

void PrintAnswer(int pos) {
  if (p[pos] != pos) {
    PrintAnswer(p[pos]);
  }
  cout << arr[pos] << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  dp[1] = 1;
  p[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int prev_max = 0;
    int prev = i;
    for (int j = 1; j < i; ++j) {
      if (arr[j] < arr[i] && dp[j] > prev_max) {
        prev_max = dp[j];
        prev = j;
      }
    }
    dp[i] = prev_max + 1;
    p[i] = prev;
  }

  int max_cnt = 0;
  int pos;
  for (int i = 1; i <= n; ++i) {
    if (max_cnt < dp[i]) {
      max_cnt = dp[i];
      pos = i;
    }
  }

  cout << max_cnt << "\n";
  PrintAnswer(pos);

  return 0;
}