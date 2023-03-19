// Sleepy Cow Herding
// http://www.usaco.org/index.php?page=viewproblem2&cpid=915

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> v(3);
  for (int i = 0; i < 3; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int d1 = v[1] - v[0];
  int d2 = v[2] - v[1];

  int min_ans, max_ans;

  if (d1 == 1 && d2 == 1) {
    min_ans = 0;
  } else if (d1 == 2 || d2 == 2) {
    min_ans = 1;
  } else {
    min_ans = 2;
  }

  max_ans = max(d1, d2) - 1;

  cout << min_ans << "\n" << max_ans << "\n";

  return 0;
}