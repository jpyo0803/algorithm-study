// 돌 그룹
// https://www.acmicpc.net/problem/12886

#include <bits/stdc++.h>

using namespace std;

int sum;

bool visited[1505][1505];

int Solve(int a, int b) {
  queue<pair<int, int>> que;
  que.emplace(a, b);
  visited[a][b] = true;

  while (que.empty() == false) {
    int a = que.front().first, b = que.front().second;
    que.pop();

    int c = sum - a - b;
    if (a == b && b == c) return 1;

    for (int i = 0; i < 2; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        vector<int> dols = {a, b, c};
        if (dols[i] == dols[j]) continue;
        int& x = dols[i] < dols[j] ? dols[i] : dols[j];
        int& y = dols[i] > dols[j] ? dols[i] : dols[j];
        y -= x;
        x += x;
        if (visited[dols[i]][dols[j]] == false) {
          visited[dols[i]][dols[j]] = true;
          que.emplace(dols[0], dols[1]);
        }
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  sum = a + b + c;

  if (sum % 3) {
    cout << "0\n";
  } else {
    cout << Solve(a, b) << "\n";
  }

  return 0;
}