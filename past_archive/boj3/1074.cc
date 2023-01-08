//
// Z
// Problem: https://www.acmicpc.net/problem/1074
//

#include <cstdio>
int N, r, c;

int recursive_call(int sz, int br, int bc, int prev_num) {
  if (sz == 1) {
    if (br == r && bc == c) {
      return prev_num;
    }
    return -1;
  }

  int hsz = sz / 2;
  int sr = br + hsz;
  int sc = bc + hsz;
  int pn = hsz * hsz;
  int ret;
  if (r < sr && c < sc) {  // 2nd {
    ret = recursive_call(hsz, br, bc, prev_num);
    if (ret != -1) return ret;
  } else if (r < sr && c >= sc) {  // 1st
    ret = recursive_call(hsz, br, bc + hsz, prev_num + pn);
    if (ret != -1) return ret;
  } else if (r >= sr && c < sc) {  // 3rd
    ret = recursive_call(hsz, br + hsz, bc, prev_num + (pn * 2));
    if (ret != -1) return ret;
  } else {
    ret = recursive_call(hsz, br + hsz, bc + hsz, prev_num + (pn * 3));
    if (ret != -1) return ret;
  }
  return -1;
}
int main() {
  scanf("%d%d%d", &N, &r, &c);
  int sz{1};
  for (int i = 0; i < N; i++) sz *= 2;

  printf("%d", recursive_call(sz, 0, 0, 0));
  return 0;
}