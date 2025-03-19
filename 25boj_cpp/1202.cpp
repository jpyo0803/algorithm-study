// 보석 도둑  
// https://www.acmicpc.net/problem/1202

/* 
    더 가치가 높은 것을 선택하여 결과적으로 suboptimal이 될 수 있을까? 
    만약 가방에 2개이상의 물품을 넣을 수 있었더라면 해당 문제상황이 발생할 수 있으나
    우리의 경우 한 가방에는 최대 하나의 보석만 가능하기에 해당되지 않음.

    알고리즘, 보석을 가치를 기준으로 정렬한다.
    가치가 높은 보석부터 이를 담을 수 있는 가장 작은 가방에 assign한다. 
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

pair<int, int> mv[300010];
int c[300010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> mv[i].first >> mv[i].second;

  for (int i = 0; i < k; ++i) cin >> c[i];

  sort(mv, mv + n);
  sort(c, c + k);

  long long ans = 0;

  priority_queue<int> pq;

  int j = 0;
  for (int i = 0; i < k; ++i) {
    while (j < n && mv[j].first <= c[i]) {
      pq.push(mv[j++].second);
    }

    if (pq.empty() == false) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << "\n";

  return 0;
}