// 주사위 굴리기
// https://www.acmicpc.net/problem/14499

#include <stdio.h>
int N, M, x, y, K;

int map[20][20];

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

class Dice {
 public:
  int t_, w_, e_, n_, s_, b_;
  int x_, y_;

  Dice(int x, int y) : t_(0), w_(0), e_(0), n_(0), s_(0), b_(0), x_(x), y_(y) {}

  int RollNorth() {
    if (!InRange(x_ - 1, y_)) return -1;
    x_ -= 1;

    int tmp = t_;
    t_ = s_;
    s_ = b_;
    b_ = n_;
    n_ = tmp;
    Update();

    return t_;
  }

  int RollWest() {
    if (!InRange(x_, y_ - 1)) return -1;
    y_ -= 1;

    int tmp = t_;
    t_ = e_;
    e_ = b_;
    b_ = w_;
    w_ = tmp;
    Update();

    return t_;
  }

  int RollEast() {
    if (!InRange(x_, y_ + 1)) return -1;
    y_ += 1;

    int tmp = t_;
    t_ = w_;
    w_ = b_;
    b_ = e_;
    e_ = tmp;
    Update();

    return t_;
  }

  int RollSouth() {
    if (!InRange(x_ + 1, y_)) return -1;
    x_ += 1;

    int tmp = t_;
    t_ = n_;
    n_ = b_;
    b_ = s_;
    s_ = tmp;
    Update();

    return t_;
  }

  void Update() {
    if (map[x_][y_] == 0) {
      map[x_][y_] = b_;
    } else {
      b_ = map[x_][y_];
      map[x_][y_] = 0;
    }
  }
};

void Solve(int x, int y) {
  Dice dice(x, y);

  for (int i = 0; i < K; i++) {
    int cmd;
    scanf("%d", &cmd);
    int ret;
    if (cmd == 1)
      ret = dice.RollEast();
    else if (cmd == 2)
      ret = dice.RollWest();
    else if (cmd == 3)
      ret = dice.RollNorth();
    else
      ret = dice.RollSouth();

    if (ret != -1) printf("%d\n", ret);
  }
}

int main() {
  scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  Solve(x, y);

  return 0;
}
