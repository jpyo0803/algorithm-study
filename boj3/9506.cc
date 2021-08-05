//
// Sum of Factors
// Problem: https://www.acmicpc.net/problem/9506
//

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
int n;
std::vector<int> factors;
int main() {
    scanf("%d", &n);
    while (n != -1) {
        factors.clear();
        factors.push_back(1);
        int sum = 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
                sum += i;
                sum += n / i;
            }
        }
        if (sum == n) {
            sort(factors.begin(), factors.end());
            printf("%d = ", n);
            for (int i = 0; i < factors.size() - 1; i++) {
                printf("%d + ", factors[i]);
            }
            printf("%d\n", factors[factors.size() - 1]);
        } else {
            printf("%d is NOT perfect.\n", n);
        }
        scanf("%d", &n);
    }

    return 0;
}

