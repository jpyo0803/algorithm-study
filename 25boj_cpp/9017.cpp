// 크로스 컨트리
// https://www.acmicpc.net/problem/9017

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 6명이 다 참가해야만 인정
  // 6명보다 많은 팀은 존재하지 않는다
  // 들어온 순서대로 1, 2, 3, ... 점씩 점수를 받는다. 이때 실격된 팀은
  // 카운트하지 않는다. 동점일 경우 5번째 선수중 가장 빨리 들어온 선수의 팀이
  // 승리. 이때 동점인 팀이 3개 이상일 경우도 고려

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> x(n);
    map<int, int> mem_cnt;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      mem_cnt[x[i]]++;
    }

    vector<int> fx;
    for (auto e : x) {
      if (mem_cnt[e] == 6) {
        fx.push_back(e);
      }
    }

    vector<int> fx_scores(fx.size());
    for (int i = 0; i < fx.size(); ++i) fx_scores[i] = i;

    map<int, vector<int>> scores_by_team;
    for (int i = 0; i < fx.size(); ++i) {
      scores_by_team[fx[i]].push_back(fx_scores[i]);
    }

    vector<pair<int, int>> ts;
    for (auto& [k, v] : scores_by_team) {
      int sum = 0;
      for (int i = 0; i < 4; ++i) {
        sum += v[i];
      }
      ts.emplace_back(k, sum);
    }

    sort(ts.begin(), ts.end(),
         [](const pair<int, int>& x, const pair<int, int>& y) {
           return x.second < y.second;
         });

    vector<int> par_teams;
    int target_val = - 1;
    for (auto [k, v] : ts) {
      if (target_val == -1) {
        target_val = v;
        par_teams.push_back(k);
      } else {
        if (v != target_val) {
          break;
        } else {
          par_teams.push_back(k);
        }
      }
    }

    int min_fifth_val = 1e9;
    int min_fifth_team = -1;
    for (auto e : par_teams) {
      if (scores_by_team[e][4] < min_fifth_val) {
        min_fifth_val = scores_by_team[e][4];
        min_fifth_team = e;
      }
    }

    cout << min_fifth_team << "\n";
  }

  return 0;
}