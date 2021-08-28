//
// Friends Network
// Problem: https://www.acmicpc.net/problem/4195
//

#include <cstdio>
#include <unordered_map>

using namespace std;
const int MAX{200000};
int T, F;
char buff[30];

unordered_map<string, int> address;
int assign_count{1};

int parent[MAX + 1];
int ppl_cnt[MAX + 1];

string a, b;

int get_parent(int curr) {
  if (parent[curr] == 0) return curr;
  int root = get_parent(parent[curr]);
  parent[curr] = root;
  return root;
}

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &F);
    for (int i = 0; i < F; i++) {
      scanf("%s", buff);
      a = buff;
      scanf("%s", buff);
      b = buff;
      int ra, rb;
      if (address[a] != 0 && address[b] != 0) {
        ra = get_parent(address[a]);
        rb = get_parent(address[b]);
        if (ra != rb) {
          ppl_cnt[ra] += ppl_cnt[rb];
          parent[rb] = ra;
        }
        printf("%d\n", ppl_cnt[ra]);
      } else if (address[a] != 0 || address[b] != 0) {
        if (address[a] != 0) {
          ra = get_parent(address[a]);
          ppl_cnt[ra] += 1;
          address[b] = assign_count;
          parent[address[b]] = ra;
          assign_count += 1;
          printf("%d\n", ppl_cnt[ra]);
        } else {
          rb = get_parent(address[b]);
          ppl_cnt[rb] += 1;
          address[a] = assign_count;
          parent[address[a]] = rb;
          assign_count += 1;
          printf("%d\n", ppl_cnt[rb]);
        }
      } else {
        address[a] = assign_count++;
        address[b] = assign_count++;
        ppl_cnt[address[a]] = 2;
        parent[address[b]] = address[a];
        printf("%d\n", ppl_cnt[address[a]]);
      }
    }

    address.clear();
    for (int i = 1; i <= assign_count; i++) {
      parent[i] = ppl_cnt[i] = 0;
    }
    assign_count = 1;
  }
  return 0;
}