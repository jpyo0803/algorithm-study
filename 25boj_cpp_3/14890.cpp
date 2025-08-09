// 경사로 
// https://www.acmicpc.net/problem/14890

#include <bits/stdc++.h>

using namespace std;

int N, L;
int arr[105][105];
int tmp[105][105];

int line[105];
bool used[105];

bool IsPlacable(int from, int to) {
  if (from < 0 || N <= to) return false;
  int v = line[from];
  for (int i = from; i <= to; ++i) {
    if (used[i]) return false;
    if (line[i] != v) return false;
  }
  return true;
}

void Place(int from, int to) {
  for (int i = from; i <= to; ++i) used[i] = true;
}

bool Check(int line_idx) {
  for (int i = 0; i < N; ++i) {
    line[i] = arr[line_idx][i];
    used[i] = false;
  }
  bool ok = true;

  int i = 0;
  while (ok && i < N) {
    if (i - 1 >= 0) {
      int diff = line[i - 1] - line[i];
      if (abs(diff) >= 2) ok = false;
      else if (diff == 1) { // need lower
        if (IsPlacable(i, i + L - 1)) {
          Place(i, i + L - 1);
          i += L;
        } else {
          ok = false;
        }
      } else if(diff == -1) { // need higher
        if (IsPlacable(i - L , i - 1)) {
          Place(i - L, i - 1);
          i++;
        } else {
          ok = false;
        }
      } else {
        i++;
      }
    } else {
      i++;
    }
  }

  return ok;
}

void Transpose() {  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      tmp[j][i] = arr[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      arr[i][j] = tmp[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) ans += Check(i);
  Transpose();
  for (int i = 0; i < N; ++i) ans += Check(i);

  cout << ans << "\n";
  return 0;
}