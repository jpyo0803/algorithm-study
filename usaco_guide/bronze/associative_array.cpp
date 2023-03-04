// Associative Array (Library Checker)
// https://judge.yosupo.jp/problem/associative_array

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int Q;
  cin >> Q;

  map<long long, long long> m;

  while (Q--) {
    long long a, b;
    cin >> a >> b;
    if (a == 0) {
      long long c;
      cin >> c;
      m[b] = c;
    } else {
      cout << m[b] << "\n";
    }
  }

  return 0;
}