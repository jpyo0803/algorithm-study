//
// Doubles
// Link: https://www.acmicpc.net/problem/4641
//

#include <cstdio>

using namespace std;

bool freq[100];

int main() {
  int x, count;
  count = 0;
  while (true) {
    scanf("%d", &x);
    if (x == -1)
      break;
    else if (x == 0) {
      for (int i = 0; i < 100; i++) freq[i] = false;
      printf("%d\n", count);
      count = 0;
    } else {
      freq[x] = true;
      if (x * 2 < 100 && freq[x * 2]) count++;
      if (x % 2 == 0 && freq[x / 2]) count++;
    }
  }

  return 0;
}