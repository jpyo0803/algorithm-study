//
// 점수계산
// Link: https://www.acmicpc.net/problem/2822
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Info {
  int key, value;
  Info(int k, int v) : key(k), value(v) {}
};

bool Comparator(Info& x, Info& y) { return x.value < y.value; }

int main() {
  vector<Info> infos;
  for (int i = 1; i <= 8; i++) {
    int score;
    cin >> score;
    infos.emplace_back(i, score);
  }

  sort(infos.begin(), infos.end(), Comparator);

  int sum = 0;
  vector<int> order;
  for (int i = 3; i < infos.size(); i++) {
    sum += infos[i].value;
    order.push_back(infos[i].key);
  }

  sort(order.begin(), order.end());
  cout << sum << endl;
  for (auto e : order) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
