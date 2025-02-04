// 햄버거 분배
// https://www.acmicpc.net/problem/19941

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  /*
    왼쪽에 있는 사람부터 내가 먹을 수 있는 햄버거중 가장 멀리 있는 것을 먹으면 될까?
    만약 왼쪽부터 가장 먼것을 먹으면 오른쪽에 위치하는 사람의 기회를 빼앗지는 않음, 적어도 동일한 결과 보장
    즉 문제가 되는 상황은 나에게 선택권이 있는데 그 다음 사람의 기회를 빼앗는 선택을 피하면됨
    만약 왼쪽부터 진행하는데 나보다 오른쪽에 밖에 햄버거가 없어 그것을 먹어 그 다음 사람의 기회를 뺐는다 해도
    전체적으로는 손해가아님
  */

  int ans = 0;
  int len = s.length();
  vector<bool> eaten(len, false);
  for (int i = 0; i < len; ++i) {
    if (s[i] == 'P') {
      for (int j = max(0, i - k); j < min(len, i + k + 1); ++j) {
        if (s[j] == 'H' && eaten[j] == false) {
          eaten[j] = true;
          ans++;
          break;
        } 
      }
    }
  }

  cout << ans << "\n";

  return 0;
}