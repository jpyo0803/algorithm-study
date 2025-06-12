// Year of the Cow (Bronze)
// https://www.acmicpc.net/problem/21235

#include <bits/stdc++.h>

using namespace std;

int n;

map<string, int> cycle = {{"Ox", 0},     {"Tiger", 1},  {"Rabbit", 2},
                          {"Dragon", 3}, {"Snake", 4},  {"Horse", 5},
                          {"Goat", 6},   {"Monkey", 7}, {"Rooster", 8},
                          {"Dog", 9},    {"Pig", 10},   {"Rat", 11}};

map<string, int> cow_pos;
map<string, string> cow_year;

int GetDistance(string from, string to, int dir) {
  int pos_from = cycle[from];
  int pos_to = cycle[to];
  int ret = 0;
  if (dir == -1) {  // prev,
    if (pos_from <= pos_to) ret -= 12;
    ret += pos_to - pos_from;
  } else {  // next
    if (pos_to <= pos_from) ret += 12;
    ret += pos_to - pos_from;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cow_pos["Bessie"] = 0;
  cow_year["Bessie"] = "Ox";

  for (int i = 0; i < n; ++i) {
    string to_cow, from_cow, t, dir, to_year;
    cin >> to_cow >> t >> t >> dir >> to_year >> t >> t >> from_cow;
    string from_year = cow_year[from_cow];

    int dist = GetDistance(from_year, to_year, dir[0] == 'p' ? -1 : 1);
    cow_pos[to_cow] = cow_pos[from_cow] + dist;
    cow_year[to_cow] = to_year;
  }

  cout << abs(cow_pos["Elsie"]) << "\n";

  return 0;
}