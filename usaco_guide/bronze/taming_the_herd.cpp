// Taming the Herd
// http://www.usaco.org/index.php?page=viewproblem2&cpid=809

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> log(N);
  for (int i = 0; i < N; ++i) {
    cin >> log[i];
  }

  log[0] = 0;

  bool ok = true;
  int min_ans = 0, max_ans = 0;
  int cnt = -1;

  for (int i = N - 1; i >= 0; --i) {
    if (log[i] == -1) {
      if (cnt == -1) {
        max_ans++;
      } else {
        cnt--;
        if (cnt == 0) {
          cnt = -1;
          min_ans++;
          max_ans++;
        }
      }
    } else {  // log != -1
      if (cnt == -1) {
        cnt = log[i];
        if (cnt == 0) {
          cnt = -1;
          min_ans++;
          max_ans++;
        }
      } else {
        cnt--;
        if (cnt != log[i]) {
          ok = false;
          break;
        }
        if (cnt == 0) {
          cnt = -1;
          min_ans++;
          max_ans++;
        }
      }
    }
  }

  if (ok) {
    cout << min_ans << " " << max_ans << "\n";
  } else {
    cout << "-1\n";
  }

  return 0;
}