//
// Shark's Dinner
// Link: https://www.acmicpc.net/problem/1671
//

#include <cstdio>
#include <vector>

using namespace std;

struct Shark {
  int size, speed, intel;
  vector<int> preys;
};

constexpr int kMaxSize = 50;
int N, a, b, c;
Shark sharks[kMaxSize];
int eaten_by[kMaxSize];
bool visited[kMaxSize];

bool CanEat(const Shark& x, const Shark& y) {
  return x.size >= y.size && x.speed >= y.speed && x.intel >= y.intel;
}
bool IsEqual(const Shark& x, const Shark& y) {
  return x.size == y.size && x.speed == y.speed && x.intel == y.intel;
}

bool DFS(int current_shark) {
  if (visited[current_shark]) return false;
  visited[current_shark] = true;

  for (auto &prey : sharks[current_shark].preys) {
    if (eaten_by[prey] == -1 || DFS(eaten_by[prey])) {
      eaten_by[prey] = current_shark;
      return true;
    }
  }

  return false;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) eaten_by[i] = -1;

  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", &sharks[i].size, &sharks[i].speed, &sharks[i].intel);
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (IsEqual(sharks[i], sharks[j])) {
        sharks[i].preys.push_back(j);
      } else {
        if (CanEat(sharks[i], sharks[j])) sharks[i].preys.push_back(j);
        if (CanEat(sharks[j], sharks[i])) sharks[j].preys.push_back(i);
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) visited[k] = false;
      DFS(j);
    }
  }

  int alive_count = 0;

  for (int i = 0; i < N; i++) {
    if (eaten_by[i] == -1) alive_count++;
  }

  printf("%d\n", alive_count);

  return 0;
}