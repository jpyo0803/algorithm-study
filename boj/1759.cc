//
// Password creation
// Problem: https://www.acmicpc.net/problem/1759
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE{15};
int L, C;
char ch;

char chars[MAX_SIZE];

bool is_moeum(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int chosen[15];

void operation(int nth, int moeum_chosen, int jaeum_chosen) {
    if (nth == C) {
        if (moeum_chosen > 0 && jaeum_chosen > 1 && moeum_chosen + jaeum_chosen == L) {
            for (int i = 0; i < L; i++) {
                cout << chars[chosen[i]];
            }
            cout << endl;
        }
        return;
    }

    if (is_moeum(chars[nth])) {
        if (moeum_chosen < L - 2) {
            chosen[moeum_chosen + jaeum_chosen] = nth;
            operation(nth + 1, moeum_chosen + 1, jaeum_chosen);
        }
    } else {
        chosen[moeum_chosen + jaeum_chosen] = nth;
        operation(nth + 1, moeum_chosen, jaeum_chosen + 1);
    }
    operation(nth + 1, moeum_chosen, jaeum_chosen);
}

int main() {
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> chars[i];
    }

    sort(chars, chars + C);
    operation(0, 0, 0);

    return 0;
}