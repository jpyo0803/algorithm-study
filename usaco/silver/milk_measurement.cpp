// Milk Measurement (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=763

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  ifstream fin("measurement.in");
  ofstream fout("measurement.out");

  int n, g;
  fin >> n >> g;
  // cin >> n >> g;

  vector<tuple<int, int, int>> vv(n);
  map<int, int> cow_prod;
  for (int i = 0; i < n; ++i) {
    fin >> get<0>(vv[i]) >> get<1>(vv[i]) >> get<2>(vv[i]);  // day, id,
    // change
    // cin >> get<0>(vv[i]) >> get<1>(vv[i]) >> get<2>(vv[i]);  // day, id,
    // change
    cow_prod[get<1>(vv[i])] = g;
  }
  sort(vv.begin(), vv.end());

  map<int, set<int>> leader_board;  // manage group
  for (int i = 0; i < n; ++i) {
    leader_board[g].insert(get<1>(vv[i]));
    leader_board[g].insert(10000000 + i);
    leader_board[g].insert(20000000 + i);
  }

  int ans = 0;

  for (auto& [day, id, chng] : vv) {
    int prev_amt = cow_prod[id];
    cow_prod[id] += chng;

    bool inc = false;
    int next_amt = prev_amt + chng;
    if (leader_board.rbegin()->first == prev_amt) {
      if (leader_board.rbegin()->second.size() > 1) {
        ans++;
        inc=true;
      } else if ((++leader_board.rbegin())->first >= next_amt) {
        // cout << "here... ";
        ans++;
        inc=true;
      }
    } else if (next_amt >= leader_board.rbegin()->first) {
      ans++;
      inc=true;
    } 

    leader_board[prev_amt].erase(id);
    if (leader_board[prev_amt].empty()) {
      leader_board.erase(prev_amt);
    }
    leader_board[next_amt].insert(id);

    // cout << "id : " << id << " / inc: " << inc << " / prev amt: " << prev_amt << " / next amt: " << next_amt  << endl; 
  }
  fout << ans << "\n";
  // cout << ans << "\n";

  return 0;
}