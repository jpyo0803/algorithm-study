// Breed Counting (Silver)
// https://www.acmicpc.net/problem/11969

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;

int h[100005];
int g[100005];
int j[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    int arr[3] = {0, 0, 0};
    if (x ==  1) { // h
      arr[0] = 1;
    } else if (x == 2) { //g
      arr[1] = 1;
    } else {// j
      arr[2] = 1;
    }

    h[i] = h[i - 1] + arr[0];
    g[i] = g[i - 1] + arr[1];
    j[i] = j[i - 1] + arr[2];
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " << j[b] - j[a - 1] << "\n";
  }

  return 0;
}