// Associative Array
// https://judge.yosupo.jp/problem/associative_array

#include <bits/stdc++.h>

using namespace std;

int q, type;
long long k, v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> q;

  map<long long, long long> mm;

  while (q--) {
    cin >> type >> k;
    if (type == 0) {
      cin >> v;
      mm[k] = v;
    } else {
      cout << mm[k] << "\n";
    }
  }

  return 0;
}