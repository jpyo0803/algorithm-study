//
// 오븐 시계
// Link: https://www.acmicpc.net/problem/2525
//

#include <iostream>

using namespace std;

int hr, minute;
int elasped_min;

int main() {
  cin >> hr >> minute >> elasped_min;

  int comp_hr = elasped_min / 60;
  int comp_min = elasped_min % 60;

  hr += comp_hr;
  minute += comp_min;

  if (minute > 59) {
    hr += 1;
    minute %= 60;
  }

  hr %= 24;
  cout << hr << " " << minute << endl;
  return 0;
}
