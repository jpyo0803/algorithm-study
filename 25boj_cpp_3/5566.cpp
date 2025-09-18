// 주사위 게임
// https://www.acmicpc.net/problem/5566

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int arr[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int x = 0;

  int i = 0;
  while (i < m) {
    int y;
    cin >> y;
    if (x + y >= n - 1) break;
    x = x + y + arr[x + y];
    if (x >= n - 1) break;
    i++;
  }

  cout << i + 1 << "\n";

  return 0;
}