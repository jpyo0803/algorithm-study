// 가로 세로 퍼즐 
// https://www.acmicpc.net/problem/2784

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<string> v;
  for (int i = 0; i < 6; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  vector<int> ans;
  sort(v.begin(), v.end());
  vector<int> perm = {0, 1, 2, 3, 4, 5};
  
  do {
    string a = string(1, v[perm[0]][0]) + v[perm[1]][0]  + v[perm[2]][0] ;
    string b = string(1, v[perm[0]][1]) + v[perm[1]][1]  + v[perm[2]][1] ;
    string c = string(1, v[perm[0]][2]) + v[perm[1]][2]  + v[perm[2]][2] ;

    if (a == v[perm[3]] && b == v[perm[4]] && c == v[perm[5]]) {
      cout << v[perm[0]] << "\n";
      cout << v[perm[1]] << "\n";
      cout << v[perm[2]] << "\n";
      return 0;
    }
  } while (next_permutation(perm.begin(), perm.end()));

  cout << "0\n";

  return 0;
}