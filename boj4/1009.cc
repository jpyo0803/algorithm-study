//
// 분산처리
// Link: https://www.acmicpc.net/problem/1009
//

#include <cstdio>
#include <cstring>
#include <vector>

int T, a, b;
bool freq[10];
std::vector<int> seq;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &a, &b);
    for (int i = 0; i < 10; i++) freq[i] = false;
    seq.clear();
    const int ld = a % 10;

    freq[ld] = true;
    seq.push_back(ld);
    int cd = ld;
    while (true) {
      cd *= ld;
      cd %= 10;
      if (freq[cd]) break;
      freq[cd] = true;
      seq.push_back(cd);
    }

    int ans = seq[(b - 1) % seq.size()];
    printf("%d\n", (ans == 0) ? 10 : ans);
  }
  return 0;
}