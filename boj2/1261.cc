//
// Algospot
// Problem: https://www.acmicpc.net/problem/1261
//

#include <iostream>
#include <deque>

using namespace std;

class info {
public:
    info(int _i, int _j, int _nb) : i(_i), j(_j), nb(_nb) {}
    int i, j, nb;
};
const int MAX{100};
int N, M;

bool map[MAX][MAX];
bool visited[MAX][MAX];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve() {
    deque<info> frontier;
    frontier.emplace_back(0, 0, 0);
    visited[0][0] = true;

    while (!frontier.empty()) {
        info u = frontier.front(); frontier.pop_front();
        if (u.i == N - 1 && u.j == M - 1) {
            return u.nb;
        }
        for (int i = 0; i < 4; i++) {
            int vi{u.i + d[i][0]}, vj{u.j + d[i][1]};
            if (vi >= 0 && vi < N && vj >= 0 && vj < M && !visited[vi][vj]) {
                visited[vi][vj] = true;
                if (map[vi][vj]) frontier.emplace_back(vi, vj, u.nb + 1);
                else frontier.emplace_front(vi, vj, u.nb);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            map[i][j] = (line[j] == '1') ? true : false;
        }
    }
    cout << solve();
    return 0;
}

