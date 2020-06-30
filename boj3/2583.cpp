//
// Youngyuk guhagi
// Problem: https://www.acmicpc.net/problem/2583
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX{100};
int N, M, K, x1, y1, x2, y2;
bool map[MAX][MAX];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int find_area(int r, int c) {
    vector<pair<int, int>> frontier, next;

    frontier.emplace_back(r, c);

    int area = 1;
    map[r][c] = true;
    while (!frontier.empty()) {
        next.clear();
        for (auto u : frontier) {
            for (int i = 0; i < 4; i++) {
                int vr = u.first + d[i][0];
                int vc = u.second + d[i][1];

                if (vr >= 0 && vr < N && vc >= 0 && vc < M && !map[vr][vc]) {
                    map[vr][vc] = true;
                    area += 1;
                    next.emplace_back(vr, vc);
                }
            }
        }
        swap(frontier, next);
    }
    return area;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                map[i][j] = true; // true means shaded
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) {
                pq.push(find_area(i, j));
            }
        }
    }

    printf("%d\n", pq.size());
    while (!pq.empty()) {
        printf("%d ", pq.top());
        pq.pop();
    }

    return 0;
}

