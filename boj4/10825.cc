//
// 국영수
// Link: https://www.acmicpc.net/problem/10825
//

#include <cstdio>
#include <algorithm>
#include <cstring>

constexpr int kMaxSize = 100000;
int N, k, y, s;
char n[11];

struct Info {
  char name[11];
  int kook, young, soo;
};

Info infos[kMaxSize];

bool compare(Info &x, Info &y) {
  if (x.kook > y.kook) return true;
  else if (x.kook < y.kook) return false;
  else {
    if (x.young < y.young) return true;
    else if (x.young > y.young) return  false;
    else {
      if (x.soo > y.soo) return true;
      else if (x.soo < y.soo) return false;
      else {
        int i = 0;
        int j = 0;
        while (i < strlen(x.name) && j < strlen(y.name)) {
          if (x.name[i] < y.name[i]) return true;
          else if (x.name[i] > y.name[i]) return false;
          i++; j++;
        }
        return strlen(x.name) < strlen(y.name);
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s%d%d%d", n, &k, &y, &s);
    strcpy(infos[i].name, n);
    infos[i].kook = k;
    infos[i].young = y;
    infos[i].soo = s;
  }

  std::sort(infos, infos + N, compare);
  for (int i = 0; i < N; i++) {
    printf("%s\n", infos[i].name);
  }
  return 0;
}

