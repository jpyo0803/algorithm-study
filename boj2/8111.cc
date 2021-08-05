//
// 0 and 1
// Problem: https://www.acmicpc.net/problem/8111
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX{20000};
int T, N;

pair<int, char> p[MAX];
bool visited[MAX];

bool solve(int N) {
    vector<int> frontier, next;
    frontier.push_back(1);
    p[1] = make_pair(-1, '1');
    visited[1] = true;

    while (!frontier.empty()) {
        next.clear();
        for (auto rem : frontier) {
            int np[2];
            np[0] = (rem * 10) % N;
            np[1] = (rem * 10 + 1) % N;

            for (int i = 0; i < 2; i++) {
                if (!visited[np[i]]) {
                    p[np[i]].first = rem;
                    p[np[i]].second = i + '0';
                    if (np[i] == 0) {
                        return true;
                    }
                    next.push_back(np[i]);
                    visited[np[i]] = true;
                }
            }
        }
        swap(frontier, next);
    }
    return false;
}

void print_result(int rem) {
    if (rem == -1) return;
    print_result(p[rem].first);
    cout << p[rem].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        memset(visited, false, sizeof(bool) * MAX);
        cin >> N;
        bool res = solve(N);
        if (res) print_result(0);
        else cout << "BRAK";
        cout << endl;
    }
    return 0;
}