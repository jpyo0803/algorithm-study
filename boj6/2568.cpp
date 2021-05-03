#include <stdio.h>

#include <set>

struct Pair {
  int x, y;
};

int N;
Pair connection[100000];
Pair tmp_connection[100000];
Pair index_tree[2000010];

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

Pair Query(int s, int e) {
  Pair ret;
  ret.x = 0;  // x = max, y = rep
  ret.y = -1;
  while (s <= e) {
    if (s % 2) {
      if (ret.x < index_tree[s].x) {
        ret.x = index_tree[s].x;
        ret.y = index_tree[s].y;
      }
      s++;
    }
    if (e % 2 == 0) {
      if (ret.x < index_tree[e].x) {
        ret.x = index_tree[e].x;
        ret.y = index_tree[e].y;
      }
      e--;
    }
    s >>= 1;
    e >>= 1;
  }
  return ret;
}

void Update(int n, int new_value, int rep) {
  index_tree[n].x = new_value;
  index_tree[n].y = rep;
  while (n > 1) {
    if (index_tree[n / 2].x < index_tree[n].x) {
      index_tree[n / 2].x = index_tree[n].x;
      index_tree[n / 2].y = index_tree[n].y;
    }
    n >>= 1;
  }
}

int parent[500010];

int main() {
  scanf("%d", &N);
  int mv = 0;
  for (int n = 0; n < N; n++) {
    scanf("%d%d", &connection[n].x, &connection[n].y);
    if (connection[n].y > mv) mv = connection[n].y;
  }

  for (int i = 0; i <= mv; i++) parent[i] = -1;

  Mergesort(0, N - 1);

  int base;
  for (base = 1; base < mv; base *= 2) {
  }

  for (int n = 0; n < N; n++) {
    Pair result = Query(base + 1, base + connection[n].y - 1);
    Update(base + connection[n].y, result.x + 1, connection[n].x);
    parent[connection[n].x] = result.y;
  }

  Pair ans = Query(base + 1, base + mv);
  printf("%d\n", N - ans.x);

  int now = ans.y;
  std::set<int> used;
  while (now != -1) {
    used.insert(now);
    now = parent[now];
  }
  for (int n = 0; n < N; n++) {
    if (used.find(connection[n].x) == used.end())
      printf("%d\n", connection[n].x);
  }
  return 0;
}
