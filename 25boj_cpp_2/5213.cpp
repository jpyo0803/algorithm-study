// 과외맨
// https://www.acmicpc.net/problem/5213

#include <bits/stdc++.h>

using namespace std;

int n;
int p[500*500];
int row[500*500];
int dist[500*500];

void PrintAns(int x) {
  if (x != p[x]) {
    PrintAns(p[x]);
  }
  cout << x + 1 << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> arr;

  int row_upto = n;
  int curr_row = 0;
  for (int i = 0; i < n * n - n / 2; ++i) {
    int a, b;
    cin >> a >> b;
    arr.emplace_back(a, b);
    if (i == row_upto) {
      if (curr_row % 2 == 0) row_upto += n - 1;
      else row_upto += n;
      curr_row++;
    }
    row[i] = curr_row;
    dist[i] = -1;
  } 

  queue<pair<int, int>> que; // curr, prev
  que.emplace(0, 0);
  dist[0] = 0;

  while (que.size()) {
    int curr = que.front().first;
    int prev = que.front().second;
    que.pop();

    p[curr] = prev;
    // cout << curr + 1 << " from " << prev + 1 << endl;

    // visit adj tiles if match
    int a = arr[curr].first, b = arr[curr].second;
    int curr_row = row[curr];

    int up_left = curr - n;
    if (up_left >= 0 && row[up_left] == row[curr] - 1 && dist[up_left] == -1 && arr[up_left].second == a) {
      dist[up_left] = dist[curr] + 1; 
      que.emplace(up_left, curr);
    }
    int up_right = curr - (n - 1);
    if (up_right >= 0 && row[up_right] == row[curr] - 1 && dist[up_right] == -1 && arr[up_right].first == b) {
      dist[up_right] = dist[curr] + 1;
      que.emplace(up_right, curr);
    }
    int left = curr - 1;
    if (left >= 0 && row[left] == curr_row && dist[left] == -1 && arr[left].second == a) {
      dist[left] = dist[curr] + 1;
      que.emplace(left, curr);
    }
    int right = curr + 1;
    if (right < arr.size() && row[right] == curr_row && dist[right] == -1 && arr[right].first == b) {
      dist[right] = dist[curr] + 1;
      que.emplace(right, curr);
    }
    int bottom_left = curr + (n - 1);
    if (bottom_left < arr.size() && row[bottom_left] == curr_row + 1 && dist[bottom_left] == -1 && arr[bottom_left].second == a) {
      dist[bottom_left] = dist[curr] + 1;
      que.emplace(bottom_left, curr);
    }
    int bottom_right = curr + n;
    if (bottom_right < arr.size() && row[bottom_right] == curr_row + 1 && dist[bottom_right] == -1 && arr[bottom_right].first == b) {
      dist[bottom_right] = dist[curr] + 1;
      que.emplace(bottom_right, curr);
    }
  }

  int s;
  for (int i = arr.size() - 1; i >= 0; --i) {
    if (dist[i] != -1) {
      s = i;
      break;
    }
  }

  cout << dist[s] + 1 << "\n";
  PrintAns(s);
  
  return 0;
}