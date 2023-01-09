// Mixing Milk
// http://www.usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int cap[3];
  int amt[3];

  for (int i = 0; i < 3; ++i) {
    cin >> cap[i] >> amt[i];
  }

  int from = 0;
  for (int i = 0; i < 100; ++i) {
    int to = (from + 1) % 3;

    int pour = min(amt[from], cap[to] - amt[to]);
    amt[from] -= pour;
    amt[to] += pour;

    from = to;
  }

  for (int i = 0; i < 3; ++i) {
    cout << amt[i] << "\n";
  }

  return 0;
}