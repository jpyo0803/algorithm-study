//
// White Snow and Seven Midgets
// Link: https://www.acmicpc.net/problem/3040
//

#include <array>
#include <cstdio>
#include <vector>

using namespace std;

array<int, 9> numbers;

void DFS(vector<int>& candidates) {
  if (candidates.size() == 7) {
    int sum = 0;
    for (auto candidate : candidates) sum += numbers[candidate];
    if (sum == 100) {
      for (auto candidate : candidates) printf("%d\n", numbers[candidate]);
    }
    return;
  }

  int begin = candidates.size() ? candidates.back() + 1 : 0;
  for (int i = begin; i < 9; i++) {
    candidates.push_back(i);
    DFS(candidates);
    candidates.pop_back();
  }
}

int main() {
  for (int i = 0; i < 9; i++) scanf("%d", &numbers[i]);
  vector<int> candidates;
  DFS(candidates);
  return 0;
}