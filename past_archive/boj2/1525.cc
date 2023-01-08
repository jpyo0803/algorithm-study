//
// Puzzle
// Problem: https://www.acmicpc.net/problem/1525
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int, int> moves;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string swap(string str, int x, int y) {
  char tmp = str[x];
  str[x] = str[y];
  str[y] = tmp;
  return std::move(str);
}

void bfs(int num) {
  vector<int> frontier, next;
  frontier.push_back(num);

  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      string num_str = to_string(u);
      int zero_idx = num_str.find('9');
      int ui = zero_idx / 3;
      int uj = zero_idx % 3;
      for (int k = 0; k < 4; k++) {
        int vi{ui + d[k][0]}, vj{uj + d[k][1]};
        if (vi >= 0 && vi < 3 && vj >= 0 && vj < 3) {
          string n_num_str = swap(num_str, zero_idx, vi * 3 + vj);
          int v = atoi(n_num_str.c_str());
          if (moves[v] == 0) {
            moves[v] = moves[u] + 1;
            next.push_back(v);
          }
        }
      }
    }
    swap(frontier, next);
  }
}

int main() {
  int num = 0, e;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      cin >> e;
      if (e == 0) e = 9;
      num = num * 10 + e;
    }
  }

  bool is_possible{true};
  int inversion_count = 0;
  string num_str = to_string(num);
  for (int i = 0; i < 8; i++) {
    if (num_str[i] == '9') continue;
    for (int j = i + 1; j < 9; j++) {
      if (num_str[j] == '9') continue;
      if (num_str[i] > num_str[j]) inversion_count += 1;
    }
  }

  if (inversion_count == 0) {
    cout << 0;
  } else if (inversion_count % 2) {
    cout << -1;
  } else {
    moves[num] = 0;
    bfs(num);
    cout << moves[123456789];
  }

  return 0;
}