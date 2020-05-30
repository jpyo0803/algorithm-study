//
// Decreasing Number
// Problem: https://www.acmicpc.net/problem/1038
//

#include <iostream>
#include <vector>

using namespace std;
int N;

int64_t bfs(int n) {
    vector<int64_t> frontier, next;
    for (int64_t i = 0; i < 10; i++) {
        frontier.push_back(i);
    }

    int count{0};
    while (!frontier.empty()) {
        next.clear();
        for (auto u : frontier) {
            if (count == n) {
                return u;
            }
            int64_t last = u % 10;
            for (int64_t v = 0; v < last; v++) {
                next.push_back(u * 10 + v);
            }
            count += 1;
        }
        swap(frontier, next);
    }
    return -1;
}
int main() {
    cin >> N;
    cout << bfs(N);

    return 0;
}