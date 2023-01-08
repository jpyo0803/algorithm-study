//
// Eureka Theory
// Link: https://www.acmicpc.net/problem/10448
//

#include <cstdio>
#include <vector>

using namespace std;

int T, K;

vector<int> trinums;

bool DFS(vector<int>& candidates, int K, int nth) {
  if (nth == 3) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      sum += trinums[candidates[i]];
    }
    return sum == K;
  }

  bool ret = false;
  int begin = candidates.size() ? candidates[nth - 1] : 0;
  for (int i = begin; i < trinums.size() && !ret; i++) {
    candidates.push_back(i);
    ret = DFS(candidates, K, nth + 1);
    candidates.pop_back();
  }
  return ret;
}

int main() {
  int i = 1;
  while (true) {
    int trinum = i * (i + 1) / 2;
    i++;
    if (trinum <= 1000)
      trinums.push_back(trinum);
    else
      break;
  }
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &K);
    vector<int> candidates;
    printf("%d\n", DFS(candidates, K, 0) ? 1 : 0);
  }
  return 0;
}