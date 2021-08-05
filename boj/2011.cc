//
// Password
// Problem: https://www.acmicpc.net/problem/2011
//

#include <iostream>

#define MODE 0 // 0 = Memoization, 1 = Tabulation
using namespace std;
const int MAX_SIZE{5000};
const int DIV_MOD{1000000};
int dp[MAX_SIZE];
string password;

#if (MODE == 0)
bool filled[MAX_SIZE];
int memo_method(int i) {
    if (i < 0) return 1;
    if (i == 0) return (password[0] != '0');
    if (filled[i]) return dp[i];

    if (password[i] >= '1' && password[i] <= '9') {
        dp[i] += memo_method(i - 1) % DIV_MOD;
        dp[i] %= DIV_MOD;
    }
    int two_digit = (password[i - 1] - '0') * 10 + (password[i] - '0');
    if (two_digit >= 10 && two_digit <= 26) {
        dp[i] += memo_method(i - 2) % DIV_MOD;
        dp[i] %= DIV_MOD;
    }
    filled[i] = true;
    return dp[i];
}
#else
int tabulate_method(int n) {
    dp[0] = (password[0] != '0');
    for (int i = 1; i <= n; i++) {
        if (password[i] >= '1' && password[i] <= '9') {
            dp[i] += dp[i - 1] % DIV_MOD;
            dp[i] %= DIV_MOD;
        }
        int two_digit = (password[i - 1] - '0') * 10 + (password[i] - '0');
        if (two_digit >= 10 && two_digit <= 26) {
            int prevprev = 1;
            if (i - 2 >= 0) prevprev = dp[i - 2];
            dp[i] += prevprev % DIV_MOD;;
            dp[i] %= DIV_MOD;
        }
    }
    return dp[n];
}
#endif

int main() {
    cin >> password;
#if (MODE == 0)
    cout << "Memoization" << endl;
    cout << memo_method(password.length() - 1);
#else
    cout << "Tabulation" << endl;
    cout << tabulate_method(password.length() - 1);
#endif
    return 0;
}

