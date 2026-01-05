// The Smallest String Concatenation
// https://codeforces.com/problemset/problem/632/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<string> sv(n);
  for (int i = 0; i < n; ++i) cin >> sv[i];
  sort(sv.begin(), sv.end(), [](const string& a, const string& b) {
    string x = a + b;
    string y = b + a;
    return x < y;
  });

  for (const auto& e : sv) {
    cout << e;
  }
  cout << "\n";

  return 0;
}