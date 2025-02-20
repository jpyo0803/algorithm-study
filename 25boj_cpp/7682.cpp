// 틱택토
// https://www.acmicpc.net/problem/7682

#include <bits/stdc++.h>

using namespace std;

int TTT(const string& in, char target) { 
  int ttt_cnt = 0;
  for (int i = 0; i < 3; ++i) {
    int offset = i * 3;
    if (in[offset] == target && in[offset + 1] == target && in[offset + 2] == target) ttt_cnt++;
  }
  // check vertical
  for (int i = 0; i < 3; ++i) {
    if (in[i] == target && in[i + 3] == target && in[i + 6] == target) ttt_cnt++;
  }
  // check diag left top to right down
  if (in[0] == target && in[4] == target && in[8] == target) ttt_cnt++;
  if (in[2] == target && in[4] == target && in[6] == target) ttt_cnt++;
  return ttt_cnt;
}

bool Solve(const string& in) {
  int x_ttt_cnt = TTT(in, 'X');
  int o_ttt_cnt = TTT(in, 'O');

  int o_cnt = 0;
  int x_cnt = 0;
  for (auto ch : in) {
    if (ch == 'O') o_cnt++;
    else if (ch == 'X') x_cnt++;
  }
  /*
    Only valid 경우
    양쪽다 ttt가 되는 경우는 없음. 한쪽이 ttt가 되면 게임 끝
    한쪽이 ttt 최대 가능 개수는 2. 3개는 7개를 두어야함 (불가능)

    만약 x가 이긴경우 x == o + 1 -> valid
    만약 o가 이긴경우 x == o -> valid

    둘다 이기지 않는 경우
    x가 5개, o가 4개 -> valid
  */

  if (x_ttt_cnt >= 1 && o_ttt_cnt == 0 && x_cnt == o_cnt + 1) return true;
  else if (x_ttt_cnt == 0 && o_ttt_cnt >= 1 && x_cnt == o_cnt) return true;
  else if (x_ttt_cnt == 0 && o_ttt_cnt == 0 && x_cnt == 5 && o_cnt == 4) return true;

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    string in;
    cin >> in;
    if (in == "end") break;

    cout << (Solve(in) == true ? "valid" : "invalid") << "\n";
  }

  return 0;
}