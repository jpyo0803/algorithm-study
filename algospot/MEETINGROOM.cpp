//
// MEETINGROOM
// Problem: https://www.algospot.com/judge/problem/read/MEETINGROOM
//

#include <algorithm>
#include <cstdio>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int C, N, ccount, scc_ccount;
vector<pair<int, int>> meetings;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> scc_id;
stack<int> stk;

int Min(int x, int y) { return x < y ? x : y; }

bool IsDisjoint(const pair<int, int>& x, const pair<int, int>& y) {
  return (x.second <= y.first) || (y.second <= x.first);
}

int TarjanSCC(int u) {
  int ret = discovered[u] = ccount++;
  stk.push(u);

  for (auto v : adj[u]) {
    if (discovered[v] == -1) {
      ret = Min(ret, TarjanSCC(v));
    } else if (scc_id[v] == -1) {
      ret = Min(ret, discovered[v]);
    }
  }

  if (ret == discovered[u]) {
    while (true) {
      int t = stk.top();
      stk.pop();
      scc_id[t] = scc_ccount;
      if (t == u) break;
    }
    scc_ccount++;
  }
  return ret;
}

void MakeGraph(vector<pair<int, int>>& meetings) {
  int len = meetings.size();
  adj.clear();
  adj = vector<vector<int>>(len * 2);

  for (int i = 0; i < len; i += 2) {
    int j = i + 1;
    adj[i + len].push_back(j);
    adj[j + len].push_back(i);
  }

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (!IsDisjoint(meetings[i], meetings[j])) {
        adj[i].push_back(j + len);
        adj[j].push_back(i + len);
      }
    }
  }

  while (!stk.empty()) stk.pop();
  ccount = scc_ccount = 0;
  discovered = scc_id = vector<int>(len * 2, -1);
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d", &N);
    meetings.clear();
    for (int n = 0; n < N; n++) {
      int ai, bi, ci, di;
      scanf("%d%d%d%d", &ai, &bi, &ci, &di);
      meetings.emplace_back(ai, bi);
      meetings.emplace_back(ci, di);
    }
    MakeGraph(meetings);

    int meet_len = meetings.size();
    for (int i = 0; i < meet_len * 2; i++) {
      if (discovered[i] == -1) TarjanSCC(i);
    }

    bool is_possible = true;
    for (int i = 0; i < meet_len; i++) {
      if (scc_id[i] == scc_id[meet_len + i]) {
        is_possible = false;
        break;
      }
    }
    if (is_possible) {
      printf("POSSIBLE\n");
      vector<int> answer(2 * N, -1);
      vector<pair<int, int>> order;
      for (int i = 0; i < 2 * meet_len; i++) {
        order.emplace_back(-scc_id[i], i);
      }
      sort(order.begin(), order.end());
      for (auto& e : order) {
        bool is_true = (e.second >= meet_len);
        int index = e.second % meet_len;
        if (answer[index] != -1) continue;
        answer[index] = is_true;
      }
      for (int i = 0; i < answer.size(); i += 2) {
        auto& p = answer[i] ? meetings[i] : meetings[i + 1];
        printf("%d %d\n", p.first, p.second);
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
