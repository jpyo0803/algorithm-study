#include <iostream>

using namespace std;

int num_op = 0;
void T(int n) {
  if (n > 0) {
    /*
    // T(n) = T(n-1) + 1
      num_op += 1;
      T(n-1);
    */
    /*
    // T(n) = T(n-1) + n;
    for (int i = 0; i < n; i++) {
      num_op += 1;
    }
    T(n-1);
    */
    /*
    // T(n) = T(n/2) + 1
    num_op += 1;
    T(n/2);
    */
    /*
    // T(n) = 2T(n/2) + 1
    num_op += 1;
    T(n/2);
    T(n/2);
    */
    /*
     // T(n) = T(n-1) + n
     for (int i = 0; i < n; i++) num_op += 1;
     T(n/2);
     */
    for (int i = 0; i < n; i++) num_op += 1;
    T(n / 2);
    T(n / 2);
    T(n / 2);
    T(n / 2);
  }
}

int main() {
  int n = 4;
  T(n);
  cout << num_op << "\n";
  return 0;
}
