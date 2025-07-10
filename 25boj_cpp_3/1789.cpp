// 수들의 합
// https://www.acmicpc.net/problem/1789

#include <bits/stdc++.h>

using namespace std;

long long s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;

  long long sum = 0;
  long long i = 1;
  while (sum + i <= s) {
    sum += i++;
  }

  cout << i - 1 << "\n";

  return 0;
}