// 링
// https://www.acmicpc.net/problem/3036

#include <bits/stdc++.h>

using namespace std;

int Gcd(int a, int b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  int A;
  cin >> A;
  N--;
  while (N--) {
    int x;
    cin >> x;
    int gcd = Gcd(A, x);
    cout << A / gcd << "/" << x / gcd << "\n";
  }
  return 0;
}