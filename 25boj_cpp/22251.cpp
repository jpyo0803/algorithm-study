// 빌런 호석
// https://www.acmicpc.net/problem/22251

#include <bits/stdc++.h>

using namespace std;

int n, k, p, x;

int delta[10][10];
int digits[8];

int ans = 0;

void Solve(int made_number, int depth, int total_delta) {
    if (depth < 0) {
      // cout << made_number << " / " << total_delta << endl;
        if (1 <= total_delta && total_delta <= p && made_number >= 1 && made_number <= n) {
          ans++;
        }
        return; 
    }

    for (int i = 0; i <= 9; ++i) {
        // cout <<digits[depth] << " to " << i << " / " << delta[digits[depth]][i] << endl;
        Solve(made_number * 10 + i,  depth - 1, total_delta + delta[digits[depth]][i]);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k >> p >> x;
  /*
    n: output, 1 <= n <= 10^k
    k: num digits
    x: input, 1 <= x <= 10^k
    p: num operations allowed
  */

  vector<vector<int>> sv;
  sv.push_back({1,1,1,0,1,1,1}); // 0
  sv.push_back({0,0,1,0,0,1,0}); // 1
  sv.push_back({1,0,1,1,1,0,1}); // 2
  sv.push_back({1,0,1,1,0,1,1}); //3
  sv.push_back({0,1,1,1,0,1,0}); //4
  sv.push_back({1,1,0,1,0,1,1}); // 5
  sv.push_back({1,1,0,1,1,1,1});//6
  sv.push_back({1,0,1,0,0,1,0});//7
  sv.push_back({1,1,1,1,1,1,1});//8
  sv.push_back({1,1,1,1,0,1,1});//9

  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j <= 9; ++j) {
        int diff = 0;
        for (int k = 0; k < 7; ++k) {
            if (sv[i][k] != sv[j][k]) diff++;
        }
        delta[i][j] = delta[j][i] = diff;
    }
  }

//   for (int i = 0; i < 10; ++i) {
//     for (int j = 0; j < 10; ++j) {
//         cout << i<<  " to " << j << " : " << delta[i][j] << endl;
//     }
//   }

  int xx = x;

  for (int i = 0; xx != 0; ++i) {
    digits[i] = xx % 10;
    xx /= 10;
  }

  Solve(0, k - 1, 0);
  
  cout << ans << "\n";

  return 0;
}