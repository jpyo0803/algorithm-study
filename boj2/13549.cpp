//
// Hide and Seek 3
// Problem: https://www.acmicpc.net/problem/13549
//

#include <iostream>
#include <deque>
using namespace std;
const int MAX{100000};
const int INF{100000000};
int N, K;
int level[MAX + 1];

int bfs(int n, int k) {
    deque<pair<int, int>> dq;
    dq.emplace_back(n, 0);

    while (!dq.empty()) {
        pair<int, int> u = dq.front(); dq.pop_front();

        if (u.first == k) {
            return u.second;
        } else {
            int v{2 * u.first};
            if (v > 0 && v <= MAX && u.second <= level[v]) {
                level[v] = u.second;
                dq.emplace_front(v, u.second);
            }
            v = u.first + 1;
            if (v >= 0 && u.second <= level[v]) {
                level[v] = u.second;
                dq.emplace_back(v, u.second + 1);
            }
            v = u.first - 1;
            if (v <= MAX && u.second <= level[v]) {
                level[v] = u.second;
                dq.emplace_back(v, u.second + 1);
            }
        }
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i <= MAX; i++) {
        level[i] = INF;
    }
    cout << bfs(N, K);

    return 0;
}