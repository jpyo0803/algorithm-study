// Fence Painting (Bronze)
// https://www.acmicpc.net/problem/11970

#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b;
  cin >> c >> d;

  int sum = (b - a) + (d - c);
  int intersection = max(0, min(b, d) - max(a, c));
  cout << sum - intersection << "\n";

  return 0;
}