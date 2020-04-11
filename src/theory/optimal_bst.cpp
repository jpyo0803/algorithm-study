//
// Implementation of optimal binary search tree
//

#include <iostream>

#define MODE 0 // 0 = memoization, 1 = tabulation

using namespace std;

const int N = 5; // [1, N]
const double max_val = 1000000000000.0;

double p_i[N + 1] = {0, 0.15, 0.1, 0.05, 0.1, 0.2}; // probability list of actual keys
double q_i[N + 1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1}; // probability list of dummy keys

double e[N + 1][N]; // expected cost of search for i ... j
double w[N + 1][N]; // sum of probability for i ... j
int root[N][N];

#if (MODE == 0)
bool e_filled[N + 3][N + 2];

double fill_w(int i, int j) {
    if (j == i - 1) {
        w[i][i - 1] = q_i[i - 1];
        return w[i][i - 1];
    }

    w[i][j] = fill_w(i, j - 1) + p_i[j] + q_i[j];
    return w[i][j];
}

void memo_optimal_bst(int i, int j) {
    if (e_filled[i][j]) return;

    if (j == i - 1) {
        e[i][i - 1] = q_i[i - 1];
        e_filled[i][j] = true;
        return;
    }

    e[i][j] = max_val;
    for (int r = i; r <= j; r++) {
        memo_optimal_bst(i, r - 1);
        memo_optimal_bst(r + 1, j);
        if (e[i][r - 1] + e[r + 1][j] + w[i][j] < e[i][j]) {
            e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
            root[i][j] = r;
        }
    }
    e_filled[i][j] = true;
    return;
}
#else
void tabulate_optimal_bst() {
    for (int i = 1; i <= N + 1; i++) {
        e[i][i - 1] = w[i][i - 1] = q_i[i - 1]; // initialize base cases
    }

    for (int l = 1; l <= N; l++) { // scope, eventually we want e[1][N]
        for (int i = 1; i <= N - l + 1; i++) { // index i
            int j = i + l - 1;
            e[i][j] = max_val;
            w[i][j] = w[i][j - 1] + p_i[j] + q_i[j];
            for (int r = i; r <= j; r++) {
                if (e[i][r - 1] + e[r + 1][j] + w[i][j] < e[i][j]) {
                    e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    root[i][j] = r;
                }
            }
        }
    }
}
#endif

int main() {
#if (MODE == 0)
    cout << "Memoization method" << endl;
    for (int i = 1; i <= N + 1; i++) {
        fill_w(i, N);
    }
    memo_optimal_bst(1, N);
#else
    cout << "Tabulation method" << endl;
    tabulate_optimal_bst();
#endif
    cout << fixed;
    cout.precision(3);

    cout << "e[1][N] = " << e[1][N] << endl;

    cout << "\ne[i, j] : " << endl;
    for (int j = N; j >= 0; j--) {
        for (int i = 1; i <= j + 1; i++) {
            cout << e[i][j];
            if (i < j + 1) cout << ", ";
        }
        cout << endl;
    }

    cout << "\nw[i, j] : " << endl;
    for (int j = N; j >= 0; j--) {
        for (int i = 1; i <= j + 1; i++) {
            cout << w[i][j];
            if (i < j + 1) cout << ", ";
        }
        cout << endl;
    }

    cout << "\nroot[i, j] : " << endl;
    for (int j = N; j >= 1; j--) {
        for (int i = 1; i <= j; i++) {
            cout << root[i][j];
            if (i < j) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}