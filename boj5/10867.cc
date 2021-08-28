//
// 중복빼고 정렬하기
// Link: https://www.acmicpc.net/problem/10867
//

#include <stdio.h>

#include <algorithm>

int Abs(int x) { return x < 0 ? -x : x; }

int N;
int arr[100000];
bool was_there[2001];

int main() {
  scanf("%d", &N);
  int arr_length = 0;
  for (int n = 0; n < N; n++) {
    int x;
    scanf("%d", &x);
    if (x < 0) x = Abs(x) + 1000;
    if (!was_there[x]) {
      was_there[x] = true;
      if (x > 1000) x = -x + 1000;
      arr[arr_length++] = x;
    }
  }

  std::sort(arr, arr + arr_length);
  for (int i = 0; i < arr_length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
