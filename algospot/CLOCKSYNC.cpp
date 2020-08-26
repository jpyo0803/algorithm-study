//
// CLOCKSYNC
// Link: https://www.algospot.com/judge/problem/read/CLOCKSYNC
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

int Min(int x, int y) { return x < y ? x : y; }

vector<vector<int>> switches = {
    {0, 1, 2},         {3, 7, 9, 11},   {4, 10, 14, 15}, {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12}, {0, 2, 14, 15},  {3, 14, 15},     {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},   {3, 4, 5, 9, 13}};

int T;
int clocks[16];
int pc = 0;
int DFS(vector<int>& num_sw_clicked) {
  if (num_sw_clicked.size() == 10) {
    int twelve_count = 0;
    int calculated_clocks[16];
    for (int i = 0; i < 16; i++) calculated_clocks[i] = clocks[i];
    for (int i = 0; i < num_sw_clicked.size(); i++) {
      int offset = num_sw_clicked[i] * 3;
      for (auto e : switches[i]) {
        calculated_clocks[e] += offset;
      }
    }
    for (int i = 0; i < 16; i++) {
      if (calculated_clocks[i] % 12 == 0) twelve_count++;
    }
    if (twelve_count == 16) {
      int sum = 0;
      for (auto clicked : num_sw_clicked) {
        sum += clicked;
      }
      return sum;
    }
    return INF;
  }

  int ret = INF;
  for (int i = 0; i < 4; i++) {
    num_sw_clicked.push_back(i);
    ret = Min(ret, DFS(num_sw_clicked));
    num_sw_clicked.pop_back();
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    for (int i = 0; i < 16; i++) scanf("%d", &clocks[i]);
    vector<int> num_sw_clicked;
    int ans = DFS(num_sw_clicked);
    printf("%d\n", ans == INF ? -1 : ans);
  }
  return 0;
}