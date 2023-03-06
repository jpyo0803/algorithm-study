// Year of the Cow (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1107

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<string, int> ani_year = {{"Ox", 0},     {"Tiger", 1},  {"Rabbit", 2},
                               {"Dragon", 3}, {"Snake", 4},  {"Horse", 5},
                               {"Goat", 6},   {"Monkey", 7}, {"Rooster", 8},
                               {"Dog", 9},    {"Pig", 10},   {"Rat", 11}};

  int N;
  cin >> N;

  map<string, string> name_ani = {{"Bessie", "Ox"}};
  map<string, int> ani_pos = {{"Bessie", 0}};

  for (int i = 0; i < N; ++i) {
    string a, dir, ani, b, tmp;
    cin >> a;
    for (int j = 0; j < 2; ++j) {
      cin >> tmp;
    }
    cin >> dir;
    cin >> ani;
    for (int j = 0; j < 2; ++j) {
      cin >> tmp;
    }
    cin >> b;

    name_ani[a] = ani;

    if (dir[0] == 'p') {  // previous
      int disp;
      if (ani_year[name_ani[a]] < ani_year[name_ani[b]]) {
        disp = ani_year[name_ani[b]] - ani_year[name_ani[a]];
      } else {
        disp = ani_year[name_ani[b]] + 12 - ani_year[name_ani[a]];
      }
      ani_pos[a] = ani_pos[b] - disp;
    } else {  // next
      int disp;
      if (ani_year[name_ani[b]] < ani_year[name_ani[a]]) {
        disp = ani_year[name_ani[a]] - ani_year[name_ani[b]];
      } else {
        disp = ani_year[name_ani[a]] + 12 - ani_year[name_ani[b]];
      }
      ani_pos[a] = ani_pos[b] + disp;
    }
  }
  cout << abs(ani_pos["Elsie"]) << "\n";

  return 0;
}