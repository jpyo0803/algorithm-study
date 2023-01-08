//
// 히스토그램에서 가장 큰 직사각형
// Link: https://www.acmicpc.net/problem/6549
//

#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
int N;
int boxes[100000];

int64_t DivideAndConquer(int left, int right) {
  if (left == right) return boxes[left];

  int mid = (left + right) / 2;

  int64_t ret = max<int64_t>(DivideAndConquer(left, mid),
                             DivideAndConquer(mid + 1, right));

  int lo = mid, hi = mid + 1;
  int height = min<int>(boxes[lo], boxes[hi]);
  ret = max<int64_t>(ret, height * 2);
  while (left < lo || hi < right) {
    if (hi < right && (left == lo || boxes[lo - 1] < boxes[hi + 1])) {
      hi++;
      height = min<int>(height, boxes[hi]);
    } else {
      lo--;
      height = min<int>(height, boxes[lo]);
    }
    ret = max<int64_t>(ret, static_cast<int64_t>(height) * (hi - lo + 1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while (N != 0) {
    for (int i = 0; i < N; i++) cin >> boxes[i];
    cout << DivideAndConquer(0, N - 1) << endl;
    cin >> N;
  }
  return 0;
}
