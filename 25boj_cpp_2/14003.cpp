// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

#include <bits/stdc++.h>

using namespace std;

int n;

int arr[1000010];
int ans[1000010];
int ans_len = 0;
int idx[1000010]; // keep true index
int p[1000010]; // to track parent

void PrintAns(int x) {
  if (p[x] != x) {
    PrintAns(p[x]);
  }
  cout << arr[x] << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int max_len = 0;
  int max_len_start;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(ans, ans + ans_len, arr[i]);
    int pos = distance(ans, it);
    ans[pos] = arr[i];
    idx[pos] = i;
    if (pos == 0) {
      p[i] = i;
    } else {
      p[i] = idx[pos - 1];
    }
    if (pos == ans_len) ans_len++;
    if (pos + 1 > max_len) {
      max_len = pos + 1;
      max_len_start = i;
    }
  }

  cout << max_len << "\n";
  PrintAns(max_len_start);

  return 0;
}