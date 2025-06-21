// Sleepy Cow Sorting (Bronze)
// https://www.acmicpc.net/problem/17028

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  
  int ans;
  for (int i = n - 2; i >= 0; --i) {
    if (v[i] > v[i + 1]) {
      cout << i + 1 << "\n";
      return 0; 
    }
  }

  cout << "0\n";

  return 0;
}