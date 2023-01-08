// 전깃줄
// https://www.acmicpc.net/problem/2565

#include <stdio.h>

int Max(int x, int y) { return x < y ? y : x; }

struct Pair {
  int x, y;
};

int N;
Pair connection[100];
Pair tmp_connection[100];
int index_tree[1010];

void Mergesort(int l, int r) {
  if (l == r) {
    tmp_connection[l] = connection[l];
    return;
  }

  int mid = (l + r) / 2;
  Mergesort(l, mid);
  Mergesort(mid + 1, r);

  int i = l, j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (tmp_connection[i].x < tmp_connection[j].x)
      connection[k++] = tmp_connection[i++];
    else
      connection[k++] = tmp_connection[j++];
  }

  while (i <= mid) connection[k++] = tmp_connection[i++];
  while (j <= r) connection[k++] = tmp_connection[j++];

  for (i = l; i <= r; i++) tmp_connection[i] = connection[i];
}

int Query(int s, int e) {
  int ret = 0;
  while (s <= e) {
    if (s % 2) ret = Max(ret, index_tree[s]);
    s++;
    if (e % 2 == 0) ret = Max(ret, index_tree[e]);
    e--;
    s >>= 1;
    e >>= 1;
  }
  return ret;
}

void Update(int n, int new_value) {
  index_tree[n] = new_value;
  while (n > 1) {
    if (index_tree[n / 2] < index_tree[n]) index_tree[n / 2] = index_tree[n];
    n >>= 1;
  }
}

int main() {
  scanf("%d", &N);
  int mv = 0;
  for (int n = 0; n < N; n++) {
    scanf("%d%d", &connection[n].x, &connection[n].y);
    if (connection[n].y > mv) mv = connection[n].y;
  }
  Mergesort(0, N - 1);

  int base;
  for (base = 1; base < mv; base *= 2) {
  }

  for (int n = 0; n < N; n++) {
    int result = Query(base, base + connection[n].y - 2);
    Update(base + connection[n].y - 1, result + 1);
  }

  printf("%d\n", N - Query(base, base + mv - 1));

  return 0;
}
