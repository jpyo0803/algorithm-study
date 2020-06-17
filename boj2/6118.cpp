//
// Hide and Seek
// Problem: https://www.acmicpc.net/problem/6118
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAX{20000};
const int INF{100000000};
int N, M, a, b;
vector<int> adj_list[MAX + 1];
int level[MAX + 1];

int which, dist, num;
void solve() {
    vector<int> frontier, next;
    frontier.push_back(1);
    int curr_level = 1;
    level[1] = curr_level;
    while (!frontier.empty()) {
        next.clear();
        num = frontier.size();
        int min_idx{INF};
        for (auto u : frontier) {
            min_idx = min(min_idx, u);
            dist = curr_level - 1;
            for (auto v : adj_list[u]) {
                if (level[v] == 0) {
                    level[v] = curr_level;
                    next.push_back(v);
                }
            }
        }
        which = min_idx;
        curr_level += 1;
        swap(frontier, next);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    solve();

    printf("%d %d %d", which, dist, num);
}

