// 베스트셀러
// https://www.acmicpc.net/problem/1302

#include <stdio.h>

#include <map>
#include <string>

using namespace std;

int N;
map<string, int> book_count;
char input[51];

int main() {
  scanf("%d", &N);
  string title;
  for (int n = 0; n < N; n++) {
    scanf("%s", input);
    book_count[input]++;
  }

  int max_count = 0;
  for (auto& e : book_count) {
    if (e.second > max_count) {
      max_count = e.second;
      title = e.first;
    }
  }

  printf("%s\n", title.c_str());
  return 0;
}
