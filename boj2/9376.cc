//
// Jailbreak
// Problem: https://www.acmicpc.net/problem/9376
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class info {
public:
    info(int _i, int _j, int _nb) : i{_i}, j{_j}, nb{_nb} {}

    int i, j, nb;
};

const int MAX{100};
const int INF{100000000};
int T, H, W;
char map[MAX + 2][MAX + 2];
int nbs[MAX + 2][MAX + 2][3];

const char SPACE = '.';
const char WALL = '*';
const char DOOR = '#';
const char PRISONER = '$';

int d[4][2] = {{1,  0},
               {-1, 0},
               {0,  1},
               {0,  -1}};

void solve(info &sp, int i) {
    deque <info> frontier;
    frontier.push_back(sp);
    nbs[sp.i][sp.j][i] = 0;

    while (!frontier.empty()) {
        info u = frontier.front();
        frontier.pop_front();
        for (int j = 0; j < 4; j++) {
            int vi{u.i + d[j][0]}, vj{u.j + d[j][1]};
            if (vi >= 0 && vi <= H + 1 && vj >= 0 && vj <= W + 1 && map[vi][vj] != WALL && nbs[vi][vj][i] == -1) {
                int vnb = u.nb + (map[vi][vj] == DOOR);
                if (map[vi][vj] == DOOR) frontier.push_back(info{vi, vj, vnb});
                else frontier.push_front(info{vi, vj, vnb});
                nbs[vi][vj][i] = vnb;
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    vector <info> sps;
    for (int tc = 0; tc < T; tc++) {
        sps.clear();
        sps.emplace_back(0, 0, 0);
        scanf("%d%d", &H, &W);
        for (int i = 0; i <= H + 1; i++) {
            for (int j = 0; j <= W + 1; j++) {
                for (int k = 0; k < 3; k++) {
                    nbs[i][j][k] = -1;
                }
            }
        }

        for (int i = 0; i <= H + 1; i++) map[i][0] = map[i][W + 1] = SPACE;
        for (int j = 0; j <= W + 1; j++) map[0][j] = map[H + 1][j] = SPACE;

        char line[MAX + 1];
        for (int i = 1; i <= H; i++) {
            scanf("%s", line);
            for (int j = 1; j <= W; j++) {
                map[i][j] = line[j - 1];
                if (map[i][j] == PRISONER) {
                    sps.emplace_back(i, j, 0);
                }
            }
        }
        for (int i = 0; i < 3; i++) solve(sps[i], i);
        int ans{INF};

        for (int i = 0; i <= H + 1; i++) {
            for (int j = 0; j <= W + 1; j++) {
                if (map[i][j] != WALL) {
                    int sum = (map[i][j] == DOOR) ? -2 : 0;
                    for (int k = 0; k < 3; k++) {
                        sum += nbs[i][j][k];
                    }
                    ans = min(ans, sum);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}