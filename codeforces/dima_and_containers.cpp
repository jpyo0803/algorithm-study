// C. Dima and Containers
// https://codeforces.com/problemset/problem/358/C

#include <bits/stdc++.h>

using namespace std;

int n, a;

int Solve(vector<int>& v) {
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < v.size(); ++i) pq.emplace(v[i], i);

  int c = 0;
  vector<pair<int, int>> ma3;
  
  while (pq.size() && ma3.size() < 3) {
    ma3.push_back(pq.top());
    pq.pop();
  }

  vector<bool> chosen(v.size(), false);
  for (int i = 0; i < v.size(); ++i) {
    bool ok = false;
    for (auto e : ma3) {
      if (e.second == i) ok = true;
    }
    if (ok) {
      chosen[i] = true;
      c++;
    }
  }

  int cc = 0;
  for (int i = 0; i < chosen.size(); ++i) {
    if (!chosen[i]) {
      cout << "pushBack\n";
    } else {
      if (cc == 0) cout << "pushStack\n";
      else if (cc == 1) cout << "pushQueue\n";
      else if (cc == 2) cout << "pushFront\n";
      cc++;
    }
  }

  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<int> v;
  while (n--) {
    cin >> a;

    if (a == 0) {
      int c = Solve(v);

      if (c == 0) cout << "0\n";
      else {
        cout << c;
        for (int i = 0; i < c; ++i) {
          if (i == 0) cout << " popStack";
          else if (i == 1) cout << " popQueue";
          else cout << " popFront";
        }
        cout << "\n";
      }
     
      v.clear();
    } else {
      v.push_back(a);
    }
  }

  if (v.size()) {
    Solve(v);
  }

  return 0;
}