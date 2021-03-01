#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;

int N, M;
int adj[101][101];
vector<int> paths[101][101];

void FloydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int new_dist = adj[i][k] + adj[k][j];
				if (new_dist < adj[i][j]) {
					adj[i][j] = new_dist;
					vector<int> new_path;
					for (int l = 0; l < paths[i][k].size(); l++) new_path.push_back(paths[i][k][l]);
					for (int l = 1; l < paths[k][j].size(); l++) new_path.push_back(paths[k][j][l]);
					paths[i][j] = new_path;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (paths[i][j].size() < 2) printf("0\n");
			else {
				printf("%d ", paths[i][j].size());
				for (auto e : paths[i][j]) {
					printf("%d ", e);
				}
				printf("\n");
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) adj[i][j] = INF;
		}
	}

	for (int m = 0; m < M; m++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u][v] = w < adj[u][v] ? w : adj[u][v];
		paths[u][v] = vector<int>{u, v};
	}
	
	FloydWarshall();

	return 0;
}
