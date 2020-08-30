//
// QUADTREE
// Problem: https://www.algospot.com/judge/problem/read/QUADTREE
//

#include <iostream>

constexpr int kMax = 1000;

using namespace std;

int C;

char input[kMax + 1];

string QuadTree(int& current_index) {
  char head = input[current_index++];
  if (head != 'x') return string(1, head);

  string ret = "x";
  string q1 = QuadTree(current_index);
  string q2 = QuadTree(current_index);
  string q3 = QuadTree(current_index);
  string q4 = QuadTree(current_index);
  ret += q3 + q4 + q1 + q2;
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%s", input);
    int start_index = 0;
    string ans = QuadTree(start_index);
    printf("%s\n", ans.c_str());
  }
  return 0;
}