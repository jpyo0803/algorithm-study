// 개미 
// https://www.acmicpc.net/problem/3048

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n1, n2, t;

bool is_left[256];
char line[30];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n1 >> n2;
  for (int i = n1 - 1; i >= 0; --i) {
    cin >> line[i];
    is_left[line[i]] = false;
  }
  for (int i = n1; i < n1 + n2; ++i) {
    cin >> line[i];
    is_left[line[i]] = true;
  }

  cin >> t;
  
  while (t > 0) {
    vector<int> swap_pos;
    for (int i = 0; i < n1 + n2 - 1; ++i) {
      if (!is_left[line[i]] && is_left[line[i + 1]]) {
        swap_pos.push_back(i);
      }
    }

    for (auto e : swap_pos) swap(line[e], line[e + 1]);

    t--;
  }

  for (int i = 0; i < n1 + n2; ++i) cout << line[i];
  cout << "\n";

  return 0;
}