//
// Yangjojang of The Year
// Link: https://www.acmicpc.net/problem/11557
//

#include <iostream>

using namespace std;

int T, N;

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    string most_druken;
    int most_value = 0;
    for (int n = 0; n < N; n++) {
      string school;
      int value;
      cin >> school >> value;
      if (value > most_value) {
        most_value = value;
        most_druken = school;
      }
    }
    cout << most_druken << endl;
  }
  return 0;
}
