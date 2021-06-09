// 소방차
// https://www.acmicpc.net/problem/2586

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

int P, F;
pair<long long, bool> p_f[200010];
vector<long long> segments[400010];

long long Abs(long long x) { return x < 0 ? -x : x; }
long long AbsDiff(long long x, long long y) { return Abs(x - y); }
long long Min(long long x, long long y) { return x < y ? x : y; }

int main() {
  scanf("%d%d", &P, &F);
  int PF = P + F;
  for (int i = 0; i < P; i++) scanf("%lld", &p_f[i].first);
  for (int i = P; i < PF; i++) {
    scanf("%lld", &p_f[i].first);
    p_f[i].second = true;
  }
  sort(p_f, p_f + PF);

  int now = PF;
  int ll = 500000, hl = 0;
  for (int i = 0; i < PF; i++) {
    p_f[i].second ? segments[--now].push_back(p_f[i].first)
                  : segments[now++].push_back(p_f[i].first);
    if (now < ll) ll = now;
    if (now > hl) hl = now;
  }

  long long ans = 0;
  for (int i = ll; i <= hl; i++) {
    if (segments[i].empty()) continue;
    long long sum = 0, min_sum = 10000000000;
    for (int j = 1; j < segments[i].size(); j += 2) {
      sum += AbsDiff(segments[i][j - 1], segments[i][j]);
    }
    min_sum = Min(min_sum, sum);
    if (segments[i].size() % 2) {
      for (int j = segments[i].size() - 1; j > 1; j -= 2) {
        sum = sum - AbsDiff(segments[i][j - 1], segments[i][j - 2]) +
              AbsDiff(segments[i][j], segments[i][j - 1]);
        min_sum = Min(min_sum, sum);
      }
    }
    ans += min_sum;
  }

  printf("%lld\n", ans);
  return 0;
}
