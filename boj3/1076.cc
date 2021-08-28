//
// Resistance
// Problem: https://www.acmicpc.net/problem/1076
//

#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> color_map;
string color;
int main() {
  color_map["black"] = 0;
  color_map["brown"] = 1;
  color_map["red"] = 2;
  color_map["orange"] = 3;
  color_map["yellow"] = 4;
  color_map["green"] = 5;
  color_map["blue"] = 6;
  color_map["violet"] = 7;
  color_map["grey"] = 8;
  color_map["white"] = 9;

  string ans = "";
  for (int i = 0; i < 2; i++) {
    cin >> color;
    ans += to_string(color_map[color]);
  }
  cin >> color;
  if (atoi(ans.c_str()) > 0) {
    ans = to_string(atoi(ans.c_str()));
    for (int i = 0; i < color_map[color]; i++) {
      ans += '0';
    }
  } else {
    ans = '0';
  }

  cout << ans;

  return 0;
}