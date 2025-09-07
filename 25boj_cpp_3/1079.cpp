// 마피아
// https://www.acmicpc.net/problem/1079

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int a[20];
int r[20][20];
int me;

vector<int> cand;

int Solve(int nc) { 
  if (cand.size() <= 1) return nc;

  int ret = 0;
  if ((cand.size() % 2) == 0) { // night
    for (int i = 0; i < cand.size(); ++i) {
      if (cand[i] == me) continue;
      int v = cand[i];
      cand.erase(cand.begin() + i);
      for (int j = 0; j < cand.size(); ++j) a[cand[j]] += r[v][cand[j]];
      ret = max(ret, Solve(nc + 1));
      for (int j = 0; j < cand.size(); ++j) a[cand[j]] -= r[v][cand[j]];
      cand.insert(cand.begin() + i, v);
    }
  } else { // day
    int ma = -1e9, mapos;
    for (int i = 0; i < cand.size(); ++i) {
      if (a[cand[i]] > ma) {
        ma = a[cand[i]];
        mapos = i;
      }
    }

    int v = cand[mapos];
    if (v == me) return nc;
    cand.erase(cand.begin() + mapos);
    ret = max(ret, Solve(nc));
    cand.insert(cand.begin() + mapos, v);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> r[i][j];
    }
  }

  cin >> me;

  for (int i = 0; i < n; ++i) cand.push_back(i);
  
  cout << Solve(0) << "\n";

  return 0;
}