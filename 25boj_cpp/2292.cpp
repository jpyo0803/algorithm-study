// 벌집
// https://www.acmicpc.net/problem/2292

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 1 = 1, 2 = 6, 3 = 12, 
  // f[s+1] = 6 + (s - 1) * 6 
  // layer 1 : 1, s = 1
  // layer 2 : 6, s = 2
  // layer 3 : 12, s = 3
  // layer 4 : 18

  int n;
  cin >> n;

  int s = 1;
  long long acc = 1;

  while (acc < n) {
    acc += 6 + (s - 1) * 6;
    s++;
  }
  cout << s << "\n";

  return 0;
}