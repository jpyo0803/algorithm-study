
// KCPC
// https://www.acmicpc.net/problem/3758

#include <bits/stdc++.h>

using namespace std;

int T, n, k, t, m, i, j, s;

struct Info {
  int tid;
  vector<int> scores;
  int total_score = 0;
  int total_submit = 0;
  int last_submit_time = 0;

  Info(int id, int k) {
    tid = id;
    scores = vector<int>(k, 0);
  }

  void CalcTotalScore() {
    for (int i = 0; i < k; ++i) {
      total_score += scores[i];
    }
  }
};

bool compare(const Info& x, const Info& y) {
  if (x.total_score == y.total_score) {
    if (x.total_submit == y.total_submit) {
      return x.last_submit_time < y.last_submit_time;
    } else {
      return x.total_submit < y.total_submit;
    }
  } else {
    return x.total_score > y.total_score;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;
  while (T--) {
    cin >> n >> k >> t >> m;
    t--;

    vector<Info> team_infos;
    for (int ii = 0; ii < n; ++ii) {
      team_infos.emplace_back(ii, k);
    }

    for (int ii = 0; ii < m; ++ii) {
      cin >> i >> j >> s;
      i--;
      j--;

      team_infos[i].scores[j] = max(team_infos[i].scores[j], s);
      team_infos[i].total_submit++;
      team_infos[i].last_submit_time = ii; 
    }

    for (int ii = 0; ii < n; ++ii) {
      team_infos[ii].CalcTotalScore();
    }

    sort(team_infos.begin(), team_infos.end(), compare);

    // cout << "t : " << t << endl;
    for (int ii = 0; ii < n; ++ii) {
      // cout << "tid : " << team_infos[ii].tid << endl;
      if (team_infos[ii].tid == t) {
        cout << ii + 1 << "\n";
        break;
      }
    }
  }

  return 0;
}