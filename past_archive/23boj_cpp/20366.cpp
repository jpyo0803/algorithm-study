// 같이 눈사람 만들래?
// https://www.acmicpc.net/problem/20366

#include <bits/stdc++.h>

using namespace std;

struct Snowman {
  long long height;
  int a, b;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; ++i) {
    cin >> h[i];
  }

  vector<Snowman> ps;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      Snowman sm;
      sm.height = h[i] + h[j];
      sm.a = i;
      sm.b = j;
      ps.push_back(sm);
    }
  }

  sort(ps.begin(), ps.end(),
       [](Snowman& x, Snowman& y) { return x.height < y.height; });

  long long ans = 1e15;

  for (int i = 0; i < ps.size(); ++i) {  // 360,000
    int j = i - 1;
    while (j >= 0) {
      if (ps[i].a != ps[j].a && ps[i].a != ps[j].b && ps[i].b != ps[j].a &&
          ps[i].b != ps[j].b) {  // exclusive
        long long diff = ps[i].height - ps[j].height;
        ans = min(ans, diff);
        break;
      } else {
        j--;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}