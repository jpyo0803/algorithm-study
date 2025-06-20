// Sleepy Cow Herding (Bronze)
// https://www.acmicpc.net/problem/17039

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> pos(3);
  for (int i = 0; i < 3; ++i) cin >> pos[i];
  sort(pos.begin(), pos.end());

  vector<int> diff(2);
  for (int i = 0; i < 2; ++i) diff[i] = pos[i + 1] - pos[i];
  sort(diff.begin(), diff.end());
  if (diff[0] == 1 && diff[1] == 1) {
    cout << "0\n";
  } else {
    if (diff[0] == 2 || diff[1] == 2) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
  }

  cout << max(diff[0], diff[1]) - 1 << "\n";

  return 0;
}