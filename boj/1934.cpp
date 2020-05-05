//
// Least common multiple
// Problem: https://www.acmicpc.net/problem/1934
//

#include <iostream>

using namespace std;
int T;
int X, Y;

int findGCD(int x, int y) {
    int larger = (x > y) ? x : y;
    int smaller = (larger == x) ? y : x;

    int rem = larger % smaller;
    while (rem != 0) {
        larger = smaller;
        smaller = rem;
        rem = larger % smaller;
    }
    return smaller;
}

int main() {
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> X >> Y;
        cout << X * Y / findGCD(X, Y) << endl;
    }
}