//
// Consecutive sum of prime numbers
//

#include <iostream>
#include <vector>
using namespace std;
const int MAX{4000000};
int N;
bool arr[MAX + 1];
void erasto(vector<int>& vec, int upto) {
  for (int i = 2; i <= upto; i++) {
    if (!arr[i]) {
      vec.push_back(i);
      for (int j = i; j <= upto; j += i) {
        arr[j] = true;
      }
    }
  }
}
int main() {
  cin >> N;
  vector<int> pn;
  erasto(pn, N);

  int i{0}, j{-1};

  int count{0}, sum{0};
  while (i < pn.size() && j < (int)pn.size()) {
    if (sum < N) {
      j++;
      sum += pn[j];
    } else if (sum > N) {
      sum -= pn[i];
      i++;
    } else {
      count += 1;
      j++;
      sum += pn[j];
    }
  }
  cout << count;
  return 0;
}