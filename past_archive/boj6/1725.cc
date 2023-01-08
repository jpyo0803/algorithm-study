// 히스토그램
// https://www.acmicpc.net/problem/1725

#include <stdio.h>

int N;
int histogram[100000];

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x < y ? y : x; }

int Solve(int s, int e) {
  if (s == e) return histogram[s];

  int mid = (s + e) / 2;
  int max_left = Solve(s, mid);
  int max_right = Solve(mid + 1, e);

  int lo = mid, hi = mid + 1;
  int min_height = 1000000009;
  int max_area = 0;
  while (true) {
    min_height = Min(min_height, Min(histogram[lo], histogram[hi]));
    max_area = Max(max_area, min_height * (hi - lo + 1));
    if (s == lo && e == hi) {
      break;
    } else if (s < lo && hi < e) {
      if (histogram[lo - 1] < histogram[hi + 1])
        hi++;
      else
        lo--;
    } else if (hi < e) {
      hi++;
    } else {
      lo--;
    }
  }
  return Max(max_area, Max(max_left, max_right));
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; n++) {
    scanf("%d", &histogram[n]);
  }
  printf("%d\n", Solve(0, N - 1));
  return 0;
}
