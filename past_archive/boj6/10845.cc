// 큐
// https://www.acmicpc.net/problem/10845

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Queue {
 public:
  Queue(int capacity) : head_(0), tail_(-1) {
    arr = reinterpret_cast<int*>(malloc(sizeof(int) * capacity));
  }

  ~Queue() { free(arr); }

  int Size() { return tail_ - head_ + 1; }

  int Empty() { return Size() == 0; }

  void Push(int x) { arr[++tail_] = x; }

  int Pop() {
    if (Empty()) return -1;
    return arr[head_++];
  }

  int Front() {
    if (Empty()) return -1;
    return arr[head_];
  }

  int Back() {
    if (Empty()) return -1;
    return arr[tail_];
  }

 private:
  int* arr;
  unsigned int head_;
  unsigned int tail_;
};

char command[6];
int x, N;

int main() {
  scanf("%d", &N);
  Queue que(N);

  for (int n = 0; n < N; n++) {
    scanf("%s", command);
    if (strcmp(command, "push") == 0) {
      scanf("%d", &x);
      que.Push(x);
    } else if (strcmp(command, "pop") == 0) {
      printf("%d\n", que.Pop());
    } else if (strcmp(command, "size") == 0) {
      printf("%d\n", que.Size());
    } else if (strcmp(command, "empty") == 0) {
      printf("%d\n", que.Empty());
    } else if (strcmp(command, "front") == 0) {
      printf("%d\n", que.Front());
    } else {
      printf("%d\n", que.Back());
    }
  }

  return 0;
}
