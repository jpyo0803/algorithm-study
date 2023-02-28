// Back and Forth (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=857

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> buckets;

int amt[2];

vector<int> ans;

void Exchange(int a, int from, int to, int sz) {
  amt[from] -= a;
  amt[to] += a;
  buckets[from][sz]--;
  buckets[to][sz]++;
}

void Revert(int a, int from, int to, int sz) {
  amt[from] += a;
  amt[to] -= a;
  buckets[from][sz]++;
  buckets[to][sz]--;
}

void Solve(int day) {
  if (day == 5) {
    ans.push_back(amt[0]);
    return;
  }

  if (day % 2) {
    for (int i = 1; i <= 100; ++i) {
      if (buckets[0][i] == 0) continue;
      int a = min(amt[0], i);
      Exchange(a, 0, 1, i);
      Solve(day + 1);
      Revert(a, 0, 1, i);
    }
  } else {
    for (int i = 1; i <= 100; ++i) {
      if (buckets[1][i] == 0) continue;
      int a = min(amt[1], i);
      Exchange(a, 1, 0, i);
      Solve(day + 1);
      Revert(a, 1, 0, i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  buckets = vector<vector<int>>(2, vector<int>(101));

  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    buckets[0][a]++;
  }

  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    buckets[1][a]++;
  }

  amt[0] = amt[1] = 1000;

  Solve(1);

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  cout << ans.size() << "\n";

  return 0;
}