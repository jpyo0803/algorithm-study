// 등수 구하기
// https://www.acmicpc.net/problem/1205

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, new_score, p;
  cin >> n >> new_score >> p;

  vector<int> scores(n);

  int min_score = 2e9 + 1;
  int max_score = -1;
  for (int i = n - 1; i >= 0; --i) {
    cin >> scores[i];
    min_score = min(min_score, scores[i]);
    max_score = max(max_score, scores[i]);
  }

  if (n >= p && new_score <= min_score) {
    // 랭킹 리스트가 꽉 차있을 때, 새 점수가 이전 점수보다 더 좋을 때만 점수가 바뀐다.
    cout << "-1\n";
  } else {
    // 리스트가 꽉 안차있을 경우
    // 또는 리스트가 꽉 차 있지만 기존의 최소 점수보다는 새 점수가 높을 경우
    // 그냥 기존 리스트에서 나보다 높은 점수의 개수를 찾으면 됨
    auto it = upper_bound(scores.begin(), scores.end(), new_score, [](int x, int y) {
      return x < y;
    });
    cout << distance(it, scores.end()) + 1 << "\n";
  }

  return 0;
}