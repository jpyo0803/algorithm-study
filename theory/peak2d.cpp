/* 
  Peak Finder 2-D.
  This algorithm finds a peak from 2-D array 
  It uses divide and conquer algorithm
  Time complexity is n*log2(m)
*/
#include <iostream>
#include <random_number_generator.hpp>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int N = 1024;

int** arr2d;
int** level;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void filler(int len, int r, int c, int val) {
  vector<pair<int, int>> frontier;
  vector<pair<int, int>> next;
  int i = 1;
  frontier.emplace_back(r, c);
  arr2d[r][c] = val;
  level[r][c] = i;
  i++;

  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      int sub_off = 2;
      for (int i = 0; i < 4; i++) {
        int vr = u.first + d[i][0];
        int vc = u.second + d[i][1];
        if (vr >= 0 && vr < N && vc >= 0 && vc < N && level[vr][vc] == 0) {
          arr2d[vr][vc] = val - 1;
          level[vr][vc] = i;
          next.emplace_back(vr, vc);
        }
      }
    }
    i++;
    val--;
    frontier.swap(next);
  }
}

int find_globmax1d(int col, int len) {
  int glob_max = 0;
  int glob_max_row_pos = 0;
  for (int i = 0; i < len; i++) {
    if (arr2d[i][col] > glob_max) {
      glob_max = arr2d[i][col];
      glob_max_row_pos = i;
    }
  }
  return glob_max_row_pos;
}

int time_complexity = 0;
int find_peak2d(int left, int right) {
  time_complexity += N;
  int mid = (left + right) / 2;
  int globmax1d = find_globmax1d(mid, N);
  if (mid - 1 >= 0 && arr2d[globmax1d][mid - 1] > arr2d[globmax1d][mid]) {
    return find_peak2d(left, mid - 1);
  } else if (mid + 1 < N && arr2d[globmax1d][mid + 1] > arr2d[globmax1d][mid]) {
    return find_peak2d(mid + 1, right);
  }
  return arr2d[globmax1d][mid];
}
int main() {
  arr2d = new int*[N];
  level = new int*[N];
  for (int i = 0; i < N; i++) {
    arr2d[i] = new int[N];
    level[i] = new int[N];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      arr2d[i][j] = level[i][j] = 0;
    }
  }

  int peak_pos_r = get_random_number(0, N - 1);
  int peak_pos_c = get_random_number(0, N - 1);
  int peak_val = N * N * 2;

  int trail_len = N*N / 4;

  filler(N, peak_pos_r, peak_pos_c, peak_val);

  int res = find_peak2d(0, N - 1);
  cout << "found val = " << res << "\nreal value = " << peak_val << endl;
  cout << "sample size = " << N*N << " / time complexity = " << time_complexity << endl;

  return 0;
}