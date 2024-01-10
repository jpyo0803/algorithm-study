// 풍선 터트리기
// https://www.acmicpc.net/problem/2346

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  list<pair<int, int>> lst;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    lst.emplace_back(x, i + 1);
  }

  while (lst.empty() == false) {
    int a = lst.front().first;
    int b = lst.front().second;
    lst.pop_front();
    a = a > 0 ? a - 1 : a;

    while (a != 0) {
      if (a < 0) {
        auto x = lst.back();
        lst.push_front(x);
        lst.pop_back();
        a++;
      } else {
        auto x = lst.front();
        lst.push_back(x);
        lst.pop_front();
        a--;
      }
    }
    cout << b << " ";
  }

  return 0;
}