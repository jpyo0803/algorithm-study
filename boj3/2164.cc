//
// Card 2
// Link: https://www.acmicpc.net/problem/2164
//

#include <cstdio>
#include <deque>

using namespace std;

int N;
deque<int> deq;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) deq.push_back(i);

  while (true) {
    if (deq.size() == 1) break;
    deq.pop_front();
    if (deq.size() == 1) break;
    deq.push_back(deq.front()); deq.pop_front();
  }
  printf("%d\n", deq.front());
  return 0;
}

