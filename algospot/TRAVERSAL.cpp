//
// TRAVERSAL
// Problem: https://algospot.com/judge/problem/read/TRAVERSAL
//

#include <cstdio>
#include <vector>

using namespace std;

int C, N;
vector<int> pv, iv;

vector<int> SubVector(const vector<int>& v, int l, int r) {
  vector<int> tmp_vector;
  for (int i = l; i < r; i++) tmp_vector.push_back(v[i]);
  return tmp_vector;
}

void PrintPostOrder(const vector<int>& pv, const vector<int>& iv) {
  if (pv.size() == 0) return;
  int root = pv[0];

  int R;
  for (int i = 0; i < pv.size(); i++) {
    if (root == iv[i]) {
      R = i;
      break;
    }
  }

  PrintPostOrder(SubVector(pv, 1, R + 1), SubVector(iv, 0, R));
  PrintPostOrder(SubVector(pv, R + 1, pv.size()),
                 SubVector(iv, R + 1, iv.size()));
  printf("%d ", root);
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    pv.clear();
    iv.clear();
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
      int e;
      scanf("%d", &e);
      pv.push_back(e);
    }
    for (int n = 0; n < N; n++) {
      int e;
      scanf("%d", &e);
      iv.push_back(e);
    }
    PrintPostOrder(pv, iv);
    printf("\n");
  }
  return 0;
}
