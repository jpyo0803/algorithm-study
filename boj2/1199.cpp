//
// Euler Tour
// Problem: https://www.acmicpc.net/problem/1199
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAX{1000};
int N;
int adj_mat[MAX + 1][MAX + 1];

vector<int> ans;
bool dfs(int curr_node, int edge_left, int start_node) {
    if (edge_left == 0 && start_node == curr_node) {
        ans.push_back(curr_node);
        return true;
    }

    for (int i = 1; i <= N; i++) {
        if (adj_mat[curr_node][i] > 0) {
            adj_mat[curr_node][i] -= 1;
            adj_mat[i][curr_node] -= 1;
            if (dfs(i, edge_left - 1, start_node)) {
                ans.push_back(curr_node);
                return true;
            }
            adj_mat[curr_node][i] += 1;
            adj_mat[i][curr_node] += 1;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);

    int total_edge{0};
    for (int i = 1; i <= N; i++) {
        int edge{0};
        for (int j = 1; j <= N; j++) {
            scanf("%d", &adj_mat[i][j]);
            edge += adj_mat[i][j];
            total_edge += adj_mat[i][j];
        }
        if (edge % 2) { // if not even, not possible
            printf("-1");
            return 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dfs(i, total_edge / 2, i)) {
            break;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }

    return 0;
}