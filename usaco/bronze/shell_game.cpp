// Shell Game (Bronze)
// https://www.acmicpc.net/problem/17027

#include <bits/stdc++.h>

using namespace std;

int n, a, b, g;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  int cnt[3]{};
  int arr[3] = {1, 2, 3};
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> g;
    swap(arr[a - 1], arr[b - 1]); 
    // 처음에 각 shell 아래에 1, 2, 3 pebble로 마킹된 상태로 두고 swap을해도 두개 이상의 다른 pebble이 같은 shell 안으로 들어갈일은 없음
    cnt[arr[g - 1] - 1]++; // guess를 들추어봤을때 본 숫자가 x라면 처음 x위치에서 출발한 pebble이 현재 거기에 있는 것이므로 x의 cnt를 증가
  }
  cout << max(cnt[0], max(cnt[1], cnt[2])) << "\n";

  return 0;
}