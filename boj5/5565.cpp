//
// 영수증
// Link: https://www.acmicpc.net/problem/5565
//


#include <iostream>

using namespace std;

int total;

int main() {
    cin >> total;
    for (int i = 0; i < 9; i++) {
        int cost;
        cin >> cost;
        total -= cost;
    }
    cout << total << endl;
    return 0;
}
