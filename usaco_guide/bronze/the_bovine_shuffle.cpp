// The Bovine Shuffle
// http://www.usaco.org/index.php?page=viewproblem2&cpid=760

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  vector<int> shuffle(N), sv(N), ev(N);
  for (int i = 0; i < N; ++i) {
    cin >> shuffle[i];
    --shuffle[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> sv[i];
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < N; ++j) {
      ev[j] = sv[shuffle[j]];
    }
    swap(sv, ev);
  }

  for (int i = 0; i < N; ++i) {
    cout << sv[i] << "\n";
  }

  return 0;
}