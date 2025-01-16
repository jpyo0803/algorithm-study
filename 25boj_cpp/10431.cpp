// 줄세우기
// https://www.acmicpc.net/problem/10431

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int p;
  cin >> p;

  while (p--) {
    int t;
    cin >> t;

    int ans = 0;

    vector<int> line;

    for (int i = 0; i < 20; ++i) {
      int h;
      cin >> h;

      int pos = -1;
      for (int j = 0; j < i; ++j) {
        if (line[j] > h) {
          pos = j;
          break;
        }
      } 

      if (pos != -1) {
        line.push_back(-1);

        for (int j = line.size() - 1; j > pos; j--) {
          line[j] = line[j - 1];
          ans++;
        }
        line[pos] = h;
      } else {
        line.push_back(h);
      }
    }

    cout << t << " " << ans << "\n";
  }

  return 0;
}