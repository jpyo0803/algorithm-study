// 친구 네트워크
// https://www.acmicpc.net/problem/4195

#include <bits/stdc++.h>

using namespace std;

int t, f, id;
string a, b;

int p[200010];
int cnt[200010];
map<string, int> name2id;

int UF(int x) {
  if (p[x] == x) return x;
  int root = UF(p[x]);
  p[x] = root;
  return root;
}

void Reset() {
  id = 0;
  for (int i = 0; i < 2 * f; ++i) {
    p[i] = i;
    cnt[i] = 0;
  }
  name2id.clear();
}

int FindId(const string& name) {
  auto it = name2id.find(name);
  if (it != name2id.end()) {
    return it->second;
  }
  int curr_id = id++;
  name2id[name] = curr_id;
  cnt[curr_id] = 1;
  return curr_id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> f;

    Reset();

    for (int i = 0; i < f; ++i) { // 1e5
      cin >> a >> b;

      int id_a = FindId(a); // log2(2e5)
      int id_b = FindId(b); // ditto

      int ra = UF(id_a);
      int rb = UF(id_b);

      if (ra != rb) {
        cnt[ra] += cnt[rb];
        p[rb] = ra;
      }

      cout << cnt[ra] << "\n";
    }
  }

  return 0;
}