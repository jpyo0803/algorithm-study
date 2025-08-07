// 달팽이는 올라가고 싶다
// https://www.acmicpc.net/problem/2869

#include <bits/stdc++.h>

using namespace std;

int a, b, v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b >> v;

  int d = a - b;
  int q = (v - a + d - 1) / d;
  cout << q + 1 << "\n";

  return 0;
}