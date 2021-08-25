// 탑
// https://www.acmicpc.net/problem/2493

#include <stdio.h>

#include <stack>
#include <utility>

using namespace std;

int N;

stack<int> towers;
stack<pair<int, int>> tmp;

int arr[500'010];

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    int h;
    scanf("%d", &h);
    towers.push(h);
  }

  while (!towers.empty()) {
    int h = towers.top();
    int i = towers.size();
    towers.pop();

    tmp.emplace(h, i);

    if (!towers.empty()) {
      int h2 = towers.top();
      int i2 = towers.size();

      while (!tmp.empty() && h2 > tmp.top().first) {
        arr[tmp.top().second] = i2;
        tmp.pop();
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}