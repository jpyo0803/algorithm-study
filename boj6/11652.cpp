// 카드
// https://www.acmicpc.net/problem/11652

#include <stdint.h>

#include <iostream>

using namespace std;

int N;
int64_t arr[100000];
int64_t tmp_arr[100000];

void Mergesort(int l, int r) {
  if (l == r) {
    tmp_arr[l] = arr[l];
    return;
  }

  int mid = (l + r) / 2;
  Mergesort(l, mid);
  Mergesort(mid + 1, r);

  int i = l, j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (tmp_arr[i] < tmp_arr[j])
      arr[k++] = tmp_arr[i++];
    else
      arr[k++] = tmp_arr[j++];
  }

  while (i <= mid) arr[k++] = tmp_arr[i++];
  while (j <= r) arr[k++] = tmp_arr[j++];
  for (int i = l; i <= r; i++) tmp_arr[i] = arr[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  for (int n = 0; n < N; n++) cin >> arr[n];
  Mergesort(0, N - 1);

  int count = 1;
  int max_count = 0;
  int max_index = 0;

  for (int n = 1; n < N; n++) {
    if (arr[n] == arr[n - 1]) {
      count++;
      if (count > max_count) {
        max_count = count;
        max_index = n;
      }
    } else {
      count = 1;
    }
  }

  cout << arr[max_index] << "\n";

  return 0;
}
