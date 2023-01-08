//
// DNA
// Link: https://www.acmicpc.net/problem/1969
//

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

constexpr int INF = 987654321;
constexpr char CHARS[4] = {'A', 'C', 'G', 'T'};

int N, M, min_dist;
string min_dist_str;

vector<string> dnas;

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    char input[M + 1];
    scanf("%s", input);
    dnas.push_back(input);
  }

  min_dist = 0;
  min_dist_str = "";
  for (int i = 0; i < M; i++) {
    int freq_cnt[4] = {
        0,
    };
    for (auto& dna : dnas) {
      for (int j = 0; j < 4; j++) {
        if (dna[i] == CHARS[j]) {
          freq_cnt[j]++;
          break;
        }
      }
    }

    int local_max = 0;
    int local_max_idx;
    for (int j = 0; j < 4; j++) {
      if (freq_cnt[j] > local_max) {
        local_max = freq_cnt[j];
        local_max_idx = j;
      }
    }
    min_dist_str += CHARS[local_max_idx];
    min_dist += N - local_max;
  }

  printf("%s\n%d\n", min_dist_str.c_str(), min_dist);

  return 0;
}