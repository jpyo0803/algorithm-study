// 랭킹전 대기열
// https://www.acmicpc.net/problem/20006

#include <bits/stdc++.h>

using namespace std;

int p, m, l;
string n;

struct Room {
  int level;
  vector<pair<int, string>> ppl;

  Room(int level_) : level(level_) {}
};

bool compare(const pair<int, string>& x, const pair<int, string>& y) {
  int x_len = x.second.length();
  int y_len = y.second.length();

  int min_len = min(x_len, y_len);
  for (int i = 0; i < min_len; ++i) {
    if (x.second[i] != y.second[i]) {
      return x.second[i] < y.second[i];
    }
  }

  return x_len < y_len;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> p >> m;

  vector<Room> rooms;

  for (int i = 0; i < p; ++i) {
    cin >> l >> n;

    bool found = false;
    for (auto& room : rooms) {
      if (room.ppl.size() < m && room.level - 10 <= l && l <= room.level + 10) {
        room.ppl.emplace_back(l, n);
        found = true;
        break;
      }
    }
    if (found == false) {
      rooms.emplace_back(l);
      rooms.back().ppl.emplace_back(l, n);
    }
  }

  for (auto& room : rooms) {
    if (room.ppl.size() == m) {
      cout << "Started!\n";
    } else {
      cout << "Waiting!\n";
    }
    sort(room.ppl.begin(), room.ppl.end(), compare);

    for (const auto& e : room.ppl) {
      cout << e.first << " " << e.second << "\n";
    }
  }

  return 0;
}