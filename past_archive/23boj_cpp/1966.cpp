// 프린터 큐
// https://www.acmicpc.net/problem/1966

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N, targ;
    cin >> N >> targ;

    queue<pair<int, int>> q;  // priority, id

    int max_prior = -1;
    vector<int> prior_cnt(10, 0);
    vector<int> priors;
    for (int i = 0; i < N; ++i) {
      int c;
      cin >> c;
      q.emplace(c, i);

      max_prior = max(max_prior, c);
      prior_cnt[c]++;

      bool exist = false;
      for (int j = 0; j < priors.size(); ++j) {
        if (c == priors[j]) {
          exist = true;
        }
      }
      if (exist == false) {
        priors.push_back(c);
      }
    }

    sort(priors.begin(), priors.end());

    int ans = 0;
    while (true) {
      auto e = q.front();
      q.pop();
      int p = e.first;
      int id = e.second;

      if (p >= max_prior) {
        ans++;
        if (id == targ) {
          break;
        }
        // just do it
        prior_cnt[p]--;
        if (prior_cnt[p] == 0) {
          priors.pop_back();
          max_prior = priors.back();
        }
      } else {
        q.push(e);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}