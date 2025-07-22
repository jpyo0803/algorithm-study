// 수라도 
// https://www.acmicpc.net/problem/34043

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  if (n == 1 || n == 3) cout << "NO\n";
  else cout << "YES\n";

  return 0;
}