//
// Seven Nanjangees
// https://www.acmicpc.net/problem/2309
//

#include <algorithm>
#include <iostream>

using namespace std;

int heights[9];
int chosen[7];
int ans[7];

void comb(int prev, int depth) {
  if (depth == 7) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += chosen[i];
    }
    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        ans[i] = chosen[i];
      }
    }
    return;
  }
  for (int i = prev + 1; i < 9; i++) {
    chosen[depth] = heights[i];
    comb(i, depth + 1);
  }
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> heights[i];
  }

  comb(-1, 0);
  sort(ans, ans + 7);
  for (int i = 0; i < 7; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}