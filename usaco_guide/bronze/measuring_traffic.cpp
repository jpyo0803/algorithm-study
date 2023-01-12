// Measuring Traffic
// http://www.usaco.org/index.php?page=viewproblem2&cpid=917

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<tuple<string, int, int>> info(N);
  for (int i = 0; i < N; ++i) {
    string a;
    int b, c;
    cin >> a >> b >> c;
    info[i] = tie(a, b, c);
  }

  // extreme range is approximately between 0 and 1e5
  // so initializing upper bound to 1e9 is fine
  int low = 0, high = 1e9;
  for (int i = N - 1; i >= 0; --i) {
    string a;
    int b, c;
    tie(a, b, c) = info[i];
    if (a[1] == 'f') {  // off
      low += b;
      high += c;
    } else if (a[1] == 'n') {  // on
      low -= c;
      high -= b;
    } else {  // none
      low = max(low, b);
      high = min(high, c);
    }
    // prevent either bound getting smaller than 0
    low = max(low, 0);
    high = max(high, 0);
  }

  cout << low << " " << high << "\n";

  low = 0, high = 1e9;
  for (int i = 0; i < N; ++i) {
    string a;
    int b, c;
    tie(a, b, c) = info[i];
    if (a[1] == 'n') {
      low += b;
      high += c;
    } else if (a[1] == 'f') {
      low -= c;
      high -= b;
    } else {
      low = max(low, b);
      high = min(high, c), 0;
    }
    low = max(low, 0);
    high = max(high, 0);
  }

  cout << low << " " << high << "\n";

  return 0;
}