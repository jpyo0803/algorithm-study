// 동전 뒤집기
// https://www.acmicpc.net/problem/1285
#include <stdio.h>

int N;
char input[22];

struct Table {
  unsigned int data[20];
  int t_count_arr[20];
  int total_t_count = 0;
};

Table arr, arr_copy;

int ans = 987654321;
unsigned int bit_mask;

int Min(int x, int y) { return x < y ? x : y; }

void FlipBit(int index) {
  arr.data[index] = ~arr.data[index] & bit_mask;
  arr.total_t_count -= arr.t_count_arr[index];
  arr.t_count_arr[index] = N - arr.t_count_arr[index];
  arr.total_t_count += arr.t_count_arr[index];
}

Table Transpose(const Table& arr) {
  Table res;
  for (int i = 0; i < N; ++i) {
    unsigned int x = 0;
    int t_count = 0;
    for (int j = 0; j < N; ++j) {
      x <<= 1;
      unsigned int bit = (arr.data[j] >> i) & 0b1;
      x |= bit;
      t_count += bit;
    }
    res.t_count_arr[i] = t_count;
    res.data[i] = x;
  }
  res.total_t_count = arr.total_t_count;
  return res;
}

void Solve(int i) {
  if (i == 2 * N) {
    ans = Min(ans, arr.total_t_count);
    return;
  }

  if (i == N) {
    arr_copy = arr;
    arr = Transpose(arr);
  }

  if (i < N) {
    Solve(i + 1);
    FlipBit(i % N);
    Solve(i + 1);
    FlipBit(i % N);
  } else {
    if ((N - arr.t_count_arr[i % N]) < arr.t_count_arr[i % N]) {
      FlipBit(i % N);
      Solve(i + 1);
      FlipBit(i % N);
    } else {
      Solve(i + 1);
    }
  }

  if (i == N) {
    arr = arr_copy;
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    bit_mask <<= 1;
    bit_mask |= 1;
  }

  for (int i = 0; i < N; ++i) {
    scanf("%s", input);
    unsigned int x = 0;
    for (int j = 0; j < N; ++j) {
      x <<= 1;
      if (input[j] == 'T') {
        x |= 1;
        ++arr.t_count_arr[i];
      }
    }
    arr.data[i] = x;
    arr.total_t_count += arr.t_count_arr[i];
  }

  Solve(0);
  printf("%d\n", ans);
  return 0;
}