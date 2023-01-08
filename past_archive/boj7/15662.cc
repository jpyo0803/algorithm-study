// 톱니바퀴 (2)
// https://www.acmicpc.net/problem/15662

#include <stdio.h>

#include <vector>

using namespace std;

class Gear {
 public:
  explicit Gear(const char* in) {
    for (int i = 0; i < 8; i++) data[i] = (in[i] == '1');
  }

  void RotateClockWise() {
    bool tmp = data[7];
    for (int i = 7; i > 0; i--) data[i] = data[i - 1];
    data[0] = tmp;
  }

  void RotateCounterClockWise() {
    bool tmp = data[0];
    for (int i = 0; i < 7; i++) data[i] = data[i + 1];
    data[7] = tmp;
  }

  bool GetPolarityRight() const { return data[2]; }

  bool GetPolarityLeft() const { return data[6]; }

  bool GetPolarityTop() const { return data[0]; }

 private:
  bool data[8];
};

int T, K, n, d;
char input[9];

vector<Gear> gears;

bool IsGearPolarityDifferent(const Gear& left, const Gear& right) {
  return left.GetPolarityRight() != right.GetPolarityLeft();
}

void UpdateLeft(int n, int d) {
  if (n - 1 >= 0) {
    if (IsGearPolarityDifferent(gears[n - 1], gears[n])) {
      UpdateLeft(n - 1, -d);
    }
  }
  if (d > 0)
    gears[n].RotateClockWise();
  else
    gears[n].RotateCounterClockWise();
}

void UpdateRight(int n, int d) {
  if (n + 1 < T) {
    if (IsGearPolarityDifferent(gears[n], gears[n + 1])) {
      UpdateRight(n + 1, -d);
    }
  }
  if (d > 0)
    gears[n].RotateClockWise();
  else
    gears[n].RotateCounterClockWise();
}

void Update(int n, int d) {
  if (n - 1 >= 0) {
    if (IsGearPolarityDifferent(gears[n - 1], gears[n])) {
      UpdateLeft(n - 1, -d);
    }
  }
  if (n + 1 < T) {
    if (IsGearPolarityDifferent(gears[n], gears[n + 1])) {
      UpdateRight(n + 1, -d);
    }
  }
  if (d > 0)
    gears[n].RotateClockWise();
  else
    gears[n].RotateCounterClockWise();
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%s", input);
    gears.emplace_back(input);
  }

  scanf("%d", &K);
  for (int k = 0; k < K; k++) {
    scanf("%d%d", &n, &d);
    Update(n - 1, d);
  }

  int ans = 0;
  for (auto& gear : gears) {
    if (gear.GetPolarityTop()) ans++;
  }
  printf("%d\n", ans);

  return 0;
}
