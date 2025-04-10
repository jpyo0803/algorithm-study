// 팰린드롬?
// https://www.acmicpc.net/problem/10942

/*
  S,E를 물어보면 S+1, E-1이 palindrome인지보면됨
  만약 E-S+1이 짝수라면 base case는 E == S + 1, 이고 E와 S+1 자리의 값이 같아야함
  만약 홀수라면 base case는 S + 1 == E - 1일때 S+1과 E-1 자리의 값이 같아야함
  dp를 위한 메모리 스페이스는 2000^2, 시간복잡도도 동일
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[2005];

int dp[2005][2005];

bool Solve(int s, int e) {
  bool is_odd = (e - s + 1) % 2;
  if (is_odd) {
    if (s == e) return 1;
  } else {
    if (s + 1 == e) return arr[s] == arr[e] ? 1 : 0;
  }

  if (dp[s][e] != -1) return dp[s][e];
 
  int ret = Solve(s + 1, e - 1);
  dp[s][e] = ((ret == 1) && (arr[s] == arr[e])) ? 1 : 0;
  return dp[s][e];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= n; ++j) 
      dp[i][j] = -1;
  
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  
  cin >> m;
  while(m--) {
    int s, e;
    cin >> s >> e;

    cout << Solve(s, e) << "\n";
  }

  return 0;
}