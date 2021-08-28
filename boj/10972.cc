//
// Next sequence
// Problem: https://www.acmicpc.net/problem/10972
//

#include <cstdio>

using namespace std;

const int MAX_SIZE{10000};
int N;
int seq[MAX_SIZE];

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &seq[i]);
  }

  bool found = false;

  for (int i = N - 2; i >= 0 && !found; i--) {
    for (int j = N - 1; j > i; j--) {
      if (seq[i] < seq[j]) {
        swap(seq[i], seq[j]);
        int limit = i + ((N - i - 1) / 2);
        for (int k = i + 1; k <= limit; k++) {
          swap(seq[k], seq[N - (k - i)]);
        }
        found = true;
        break;
      }
    }
  }

  if (found) {
    for (int i = 0; i < N; i++) {
      printf("%d ", seq[i]);
    }
  } else {
    printf("-1");
  }
  return 0;
}