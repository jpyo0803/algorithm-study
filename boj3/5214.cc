//
// Transfer
// Problem: https://www.acmicpc.net/problem/5214
//

#include <cstdio>
#include <vector>

using namespace std;

const int N_MAX{100000};
const int M_MAX{1000};
int N, K, M, s, v, t;

vector<int> adj_list[N_MAX + M_MAX + 1];
bool visited[N_MAX + M_MAX + 1];

int solve(int start) {
    vector<int> frontier, next;
    frontier.push_back(start);
    visited[start] = true;

    int level{1};
    while (!frontier.empty()) {
        next.clear();
        for (auto& u : frontier) {
            if (u == N) {
                return level;
            }
            for (auto& ht : adj_list[u]) {
                for (auto& v : adj_list[ht]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        next.push_back(v);
                    }
                }
            }
        }
        level += 1;
        swap(frontier, next);
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &N, &K, &M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &s);
            adj_list[s].push_back(N_MAX + i);
            adj_list[N_MAX + i].push_back(s);
        }
    }

    printf("%d", solve(1));
    return 0;
}