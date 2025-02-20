// 숫자고르기
// https://www.acmicpc.net/problem/2668

#include <bits/stdc++.h>

using namespace std;

int n;

int arr[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  /*
    1 2 3
    2 3 1
    사이클 찾기
  */

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr[i]--;
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    vector<bool> visited(n, false);

    int s = i;
    visited[s] = true;
    int curr = i;

    vector<int> cand;
    cand.push_back(curr);
    int next;
    while (true) {
      next = arr[curr];
      if (visited[next] == false) {
        cand.push_back(next);
        curr = next;
        visited[next] = true;
      } else {
        break;
      }
    }
    if (next == s) {
      for (auto e : cand) {
        ans.push_back(e);
      }
    }
  }

  vector<bool> exist(n + 1, false);
  for (auto e : ans) exist[e + 1] = true;

  vector<int> real_ans;
  for (int i = 1; i <= n; ++i) {
    if (exist[i]) real_ans.push_back(i);  
  }

  cout << real_ans.size() << "\n";
  for (auto e : real_ans) {
    cout << e << "\n";
  }

  return 0;
}