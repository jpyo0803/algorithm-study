// 찾기
// https://www.acmicpc.net/problem/1786

#include <bits/stdc++.h>

using namespace std;

string t, p;
vector<int> ft;

int GetFT(int j) {
  if (j < 0) return 0;
  return ft[j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getline(cin, t);
  getline(cin, p);

  int t_len = t.length();
  int p_len = p.length();

  int i = 1, j = 0;
  ft.push_back(0);
  while (i + j < p_len) {
    if (p[i + j] == p[j]) {
      j++;
      ft.push_back(j);
    } else {
      if (j == 0) {
        i++;
        ft.push_back(0);
      } else {
        int L = GetFT(j - 1);
        i += j - L;
        j = L;
      }
    }
  }

  i = 0;
  j = 0;

  vector<int> ans;
  while (i + j < t_len) {
    if (t[i + j] != p[j]) {
      if (j == 0) {
        i++;
      } else {
        int L = GetFT(j - 1);
        i += j - L;
        j = L;
      }
    } else {
      j++;
      if (j == p_len) {
        ans.push_back(i + 1);
        int L = GetFT(j - 1);
        i += j - L;
        j = L;
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";
  cout << "\n";

  return 0;
}