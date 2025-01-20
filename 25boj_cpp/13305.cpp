// 
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  /*
    가격은 long long
    특정 도시에서 시작한다고 하면 그 도시의 기름가격보다 더 싼곳이 나타날때까지 주행할수있도록 충분히 사둔다.
  */

  int n;
  cin >> n;
  vector<int> e(n - 1); // edge
  vector<int> v(n); // vertex

  for (int i = 0; i < n - 1; ++i) cin >> e[i];
  for (int i = 0; i < n; ++i) cin >> v[i];
  v[n - 1] = 0;

  long long ans = 0;
  int min_price = v[0];
  int dist = 0;

  int pos = 0;
  while (pos < n - 1) {
    dist += e[pos];
    if (v[pos + 1] < min_price) {
      ans += (long long)min_price * dist;

      dist = 0;
      min_price = v[pos + 1];
    } 
    pos++;
  }    

  cout << ans << "\n";  

  return 0;
}