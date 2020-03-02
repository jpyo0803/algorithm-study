/*
 This dfs example can explore every graph 
 and also classifies tree edge, forward edge, backward edge, and cross edge
*/

#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> nodes[7];
int parent[7];
int depth[7];
int groups[7];

void dfs_visit(int cn, int group, int ith) {
    printf("%d-th : %d\n", ith, cn);
    for (auto nn : nodes[cn]) {
        if (parent[nn] == -1) {
            printf("%d -> %d : tree edge\n", cn, nn);
            parent[nn] = cn;
            depth[nn] = ith + 1;
            groups[nn] = group;
            dfs_visit(nn, group, ith + 1);
        } else {
            if (groups[cn] == groups[nn]) {
                if (depth[cn] < depth[nn]) {
                    printf("%d -> %d : forward edge\n", cn, nn);
                } else {
                    printf("%d -> %d : backward edge\n", cn, nn);
                }
            } else {
                printf("%d -> %d : cross edge\n", cn, nn);
            }
        }
    }
}
void dfs() {
    for (int i = 1; i < 7; i++) parent[i] = -1;
    int group = 1;
    for (int i = 1; i < 7; i++) {
        if (parent[i] == -1) {
            parent[i] = 0;
            depth[i] = 1;
            groups[i] = group;
            dfs_visit(i, group++, 1);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a ,b;
        scanf("%d%d", &a, &b);
        nodes[a].push_back(b);
    }

    dfs();
    return 0;
}