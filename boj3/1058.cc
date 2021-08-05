//
// Friend
// Problem: https://www.acmicpc.net/problem/1058
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAX{50};
int N;

bool adj_mat[MAX][MAX];
int num_friends[MAX];

bool visited[MAX];

int friend_2(int target) {
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    visited[target] = true;
    vector<int> frontier, next;
    frontier.push_back(target);

    int level{0};
    int num_friend{0};
    while (!frontier.empty()) {
        next.clear();
        for (auto u : frontier) {
            for (int v = 0; v < N; v++) {
                if (adj_mat[u][v] && !visited[v]) {
                    visited[v] = true;
                    next.push_back(v);
                    num_friend += 1;
                }
            }
        }
        level += 1;
        swap(frontier, next);
        if (level == 2) {
            break;
        }
    }
    return num_friend;
}

int main() {
    scanf("%d", &N);

    char input[MAX + 1];
    for (int i = 0; i < N; i++) {
        scanf("%s", &input);
        for (int j = 0; j < N; j++) {
            adj_mat[i][j] = (input[j] == 'Y');
        }
    }

    int max_num_friend{0};
    for (int i = 0; i < N; i++) {
        int nf = friend_2(i);
        if (max_num_friend < nf) {
            max_num_friend = nf;
        }
    }
    printf("%d", max_num_friend);
    return 0;
}