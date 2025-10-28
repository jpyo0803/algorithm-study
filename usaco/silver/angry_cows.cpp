// (Silver)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;
int arr[50005];

bool F(int r) {
  int cnt = 1;
  int start = arr[0];
  for (int i = 0; i < n; ++i) {
    if (arr[i] > start + 2 * r) {
      start = arr[i];
      cnt++;
    } 
  }
  return cnt <= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);

  int lo = 0, hi = 1e9 + 1;
  for (int dif = hi - lo; dif > 0; dif /= 2) {
    while (hi - dif >= lo && F(hi - dif)) hi -= dif;
  }
  cout << hi << "\n";

  return 0;
}