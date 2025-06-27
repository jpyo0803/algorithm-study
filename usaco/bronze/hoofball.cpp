// Hoofball (Bronze)
// https://www.acmicpc.net/problem/15752

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105];

int GetNext(int x) {
  int l = 1e9;
  int r = 1e9;
  if (x - 1 >= 0) l = arr[x] - arr[x - 1];
  if (x + 1 < n) r = arr[x + 1] - arr[x];
  if (l <= r) return x - 1;
  return x + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);

  vector<pair<int, int>> cp;  // cycle-pair
  for (int i = 0; i < n - 1; ++i) {
    int next1 = GetNext(i);
    int next2 = GetNext(i + 1);
    if (next1 == i + 1 && next2 == i) {
      cp.emplace_back(i, i + 1);
    }
  }

  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    cnt[GetNext(i)]++;
  }

  int ans = 0;
  for (auto e : cnt) {
    if (e == 0) ans++;
  }

  for (auto e : cp) {
    if (cnt[e.first] == 1 && cnt[e.second] == 1) ans++;
  }

  cout << ans << "\n";

  return 0;
}