//
// Inspection
// Problem: https://www.acmicpc.net/problem/2981
//

#include <cstdio>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const int MAX{100};
const int INF{1000000000};
int N, e;
int nums[MAX];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &N);
    vector<int> nums, pn, diff;
    for (int i = 0; i < N; i++) {
        scanf("%d", &e);
        nums.push_back(e);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            diff.push_back(abs(nums[i] - nums[j]));
        }
    }

    int overall_gcd = diff[0];
    for (int i = 1; i < diff.size(); i++) {
        overall_gcd = gcd(overall_gcd, diff[i]);
    }

    set<int> ans;
    ans.insert(overall_gcd);

    for (int i = 2; i <= sqrt(overall_gcd); i++) {
        if (overall_gcd % i == 0) {
            ans.insert(i);
            ans.insert(overall_gcd / i);
        }
    }

    for (auto it : ans) {
        printf("%d ", it);
    }

    return 0;
}
