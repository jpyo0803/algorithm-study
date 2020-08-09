//
// Chicken Delivery
// Link: https://www.acmicpc.net/problem/15686
//

#include <cmath>
#include <cstdio>

using namespace std;

constexpr int kMaxSize = 50;
constexpr int INF = 987654321;
int N, M, input;
int glob_min = INF;

int num_house = 0;
int num_chicken = 0;
int houses_x[kMaxSize * 2];
int houses_y[kMaxSize * 2];
int chickens_x[13];
int chickens_y[13];
int select_arr[13];

int ChickenDistance(int hx, int hy, int cx, int cy) {
  return abs(hx - cx) + abs(hy - cy);
}

void DFS(int n, int select_arr[], int nth) {
  if (nth == M) {
    int sum_cd = 0;
    for (int i = 0; i < num_house; i++) {
      int local_min = INF;
      for (int j = 0; j < nth; j++) {
        int cd =
            ChickenDistance(houses_x[i], houses_y[i], chickens_x[select_arr[j]],
                            chickens_y[select_arr[j]]);
        local_min = cd < local_min ? cd : local_min;
      }
      sum_cd += local_min;
    }
    glob_min = sum_cd < glob_min ? sum_cd : glob_min;
  } else {
    int start = nth == 0 ? 0 : select_arr[nth - 1] + 1;

    for (int i = start; i < n; i++) {
      select_arr[nth] = i;
      DFS(n, select_arr, nth + 1);
    }
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &input);
      if (input == 1) {
        houses_x[num_house] = i;
        houses_y[num_house] = j;
        num_house++;
      } else if (input == 2) {
        chickens_x[num_chicken] = i;
        chickens_y[num_chicken] = j;
        num_chicken++;
      }
    }
  }
  DFS(num_chicken, select_arr, 0);
  printf("%d\n", glob_min);
  return 0;
}