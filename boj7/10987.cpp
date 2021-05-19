// 모음의 개수
// https://www.acmicpc.net/problem/10987

#include <stdio.h>
#include <string.h>

char input[101];
char moeum[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
  scanf("%s", input);
  int moeum_count = 0;

  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    char ch = input[i];
    bool is_moeum = false;
    for (int j = 0; j < 5; j++) {
      if (ch == moeum[j]) is_moeum = true;
    }
    if (is_moeum) moeum_count++;
  }
  printf("%d\n", moeum_count);

  return 0;
}
