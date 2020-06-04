//
// Relatively Prime Number
// Problem: https://www.acmicpc.net/problem/4355
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;
const int MAX{31622};
int N;
bool arr[MAX + 1];
void erasto(vector<int>& pn, int upto) {
    for (int i = 2; i <= upto; i++) {
        if (!arr[i]) {
            pn.push_back(i);
            for (int j = i; j <= upto; j += i) {
                arr[j] = true;
            }
        }
    }
}
int main() {
    cin >> N;
    vector<int> pn;
    unordered_set<int> factors;
    erasto(pn, MAX);
    do {
        int i = 0;
        uint64_t ans = N;
        while (N != 1 && i < pn.size()) {
            if (N % pn[i] == 0) {
                factors.insert(pn[i]);
                N /= pn[i];
            } else {
                i += 1;
            }
        }
        if (N != 1) {
            factors.insert(N);
        }
        for (auto factor : factors) {
            ans *= (factor - 1);
        }
        for (auto factor : factors) {
            ans /= factor;
        }
        cout << ans << endl;
        factors.clear();
        cin >> N;
    } while (N != 0);

    return 0;
}