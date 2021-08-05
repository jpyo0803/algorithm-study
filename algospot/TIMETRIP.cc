//
// TIMETRIP
// Problem: https://www.algospot.com/judge/problem/read/TIMETRIP
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }

int C, V, W;

vector<int> dist_min, dist_max;
vector<vector<pair<int, int>>> adj;

void TimeTrip(int s, int t) {
	dist_min[s] = dist_max[s] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int u = 0; u < V; u++) {
			for (int v = 0; v < V; v++) {
				dist_min[v] = Min(dist_min[v], dist_min[u] + adj[u][v].first);
				dist_max[v] = Max(dist_max[v], dist_max[u] + adj[u][v].second);
			}
		}
	}

	bool neg_cycle = false, pos_cycle = false;
	for (int u = 0; u < V; u++) {
		for (int v = 0; v < V; v++) {
			if (!neg_cycle && Min(dist_min[v], dist_min[u] + adj[u][v].first) < dist_min[v]) neg_cycle = true;
			if (!pos_cycle && Max(dist_max[v], dist_max[u] + adj[u][v].second) > dist_max[v]) pos_cycle = true;
		}
	}

	if (dist_min[t] > INF - 200000) {
		printf("UNREACHABLE\n");
		return;
	}

	if (neg_cycle) printf("INFINITY ");
	else printf("%d ", dist_min[t]);
	if (pos_cycle) printf("INFINITY\n");
	else printf("%d\n", dist_max[t]);
}

int main() {
	scanf("%d", &C);
	for (int c = 0; c < C; c++) {
		scanf("%d%d", &V, &W);
		dist_min = vector<int>(V, INF);
		dist_max = vector<int>(V, -INF);
		adj = vector<vector<pair<int, int>>>(V, vector<pair<int, int>>(V, make_pair(INF, -INF)));

		for (int w = 0; w < W; w++) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			adj[a][b].first = Min(adj[a][b].first, d);
			adj[a][b].second = Max(adj[a][b].second, d);
		}

		TimeTrip(0, 1);
	}
	
	return 0;
}
