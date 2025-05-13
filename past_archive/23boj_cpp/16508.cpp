// 전공책
// https://www.acmicpc.net/problem/16508

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string T;
  cin >> T;

  int N;
  cin >> N;

  vector<pair<int, vector<int>>> vv(N,
                                    pair<int, vector<int>>(0, vector<int>(26)));
  for (int i = 0; i < N; ++i) {
    int c;
    string w;
    cin >> c >> w;
    vv[i].first = c;
    for (int j = 0; j < w.length(); ++j) {
      vv[i].second[w[j] - 'A']++;
    }
  }

  sort(vv.begin(), vv.end());

  int ans = 1e9;

  vector<int> tvec(26);
  for (int i = 0; i < T.length(); ++i) {
    tvec[T[i] - 'A']++;
  }

  for (int i = 0; i < (1 << N); ++i) {
    vector<int> cvec(26);
    int cost = 0;
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < 26; ++k) {
          cvec[k] += vv[j].second[k];
        }
        cost += vv[j].first;
      }
    }
    bool ok = true;
    for (int j = 0; j < 26; ++j) {
      if (cvec[j] < tvec[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = min(ans, cost);
    }
  }

  if (ans == 1e9) {
    ans = -1;
  }
  cout << ans << "\n";

  return 0;
}