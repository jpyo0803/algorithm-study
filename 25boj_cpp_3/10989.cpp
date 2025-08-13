// 수 정렬하기 3
// https://www.acmicpc.net/problem/10989

#include <bits/stdc++.h>

using namespace std;

int n;
int cnt[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  for (int i = 1; i <= 1e4; ++i) {
    while (cnt[i]--) {
      cout << i << "\n";
    }
  }

  return 0;
}