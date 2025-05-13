// 톱니바퀴 (2)
// https://www.acmicpc.net/problem/15662

#include <bits/stdc++.h>

using namespace std;

struct Gear {
  vector<bool> teeth;

  int head = 0;

  void RotateCW() {
    head--;
    if (head < 0) head += 8;
  }

  void RotateCCW() {
    head++;
    head %= 8;
  }
  bool GetLeft() {
    int pos = head - 2;
    if (pos < 0) pos += 8;
    return teeth[pos];
  }

  bool GetRight() { return teeth[(head + 2) % 8]; }

  bool GetHead() const { return teeth[head]; }
};

void Solve(vector<Gear>& gears, int pos, Gear prev_gear, int mov_dir,
           int prev_rot_dir) {  // -1 = left, 0 = start, 1 = right
  Gear next_gear = gears[pos];
  if (mov_dir == 0) {          // start
    if (prev_rot_dir == -1) {  // prev_rot_dir == -1 -> CCW
      gears[pos].RotateCCW();
    } else if (prev_rot_dir == 1) {
      gears[pos].RotateCW();
    }

    if (pos - 1 >= 0) {
      Solve(gears, pos - 1, next_gear, -1, prev_rot_dir);
    }
    if (pos + 1 < gears.size()) {
      Solve(gears, pos + 1, next_gear, 1, prev_rot_dir);
    }
  } else if (mov_dir == -1) {  // left
    if (prev_gear.GetLeft() != gears[pos].GetRight()) {
      if (prev_rot_dir == -1) {
        // need to CW
        gears[pos].RotateCW();
      } else if (prev_rot_dir == 1) {
        gears[pos].RotateCCW();
      }
      if (pos - 1 >= 0) {
        Solve(gears, pos - 1, next_gear, -1, -prev_rot_dir);
      }
    }
  } else if (mov_dir == 1) {  // right
    if (prev_gear.GetRight() != gears[pos].GetLeft()) {
      if (prev_rot_dir == -1) {
        // need to CW
        gears[pos].RotateCW();
      } else if (prev_rot_dir == 1) {
        gears[pos].RotateCCW();
      }
      if (pos + 1 < gears.size()) {
        Solve(gears, pos + 1, next_gear, 1, -prev_rot_dir);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  vector<Gear> gears(T);
  for (int i = 0; i < T; ++i) {
    string s;
    cin >> s;
    for (auto ch : s) {
      if (ch == '0') {  // North
        gears[i].teeth.push_back(false);
      } else {
        gears[i].teeth.push_back(true);
      }
    }
  }

  int K;
  cin >> K;
  while (K--) {
    int a, b;
    cin >> a >> b;
    a--;

    Solve(gears, a, gears[a], 0, b);
  }

  int ans = 0;
  for (const auto& e : gears) {
    if (e.GetHead() == true) {
      ++ans;
    }
  }

  cout << ans << "\n";

  return 0;
}