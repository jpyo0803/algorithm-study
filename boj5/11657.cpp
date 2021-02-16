//
// 타임머신
// Link: https://www.acmicpc.net/problem/11657
//

#include <cstdio>
#include <vector>
#include <cstdint>
#include <cinttypes>

using namespace std;

constexpr int INF = 987654321;

struct Edge {
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	int u, v, w;
};

vector<Edge> edges;
vector<int64_t> d;
int N, M;

bool BellmanFord(const vector<Edge>& edges) {
	d = vector<int64_t>(N + 1, INF);
	
	d[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (auto& edge : edges) {
			if (d[edge.u] == INF) continue;  // INF + negative weight edge -> relaxes, when this shouldn't be relaxed
			if (d[edge.v] > d[edge.u] + edge.w) {
				d[edge.v] = d[edge.u] + edge.w;
			}
		}
	}

	for (auto& edge : edges) {
		if (d[edge.u] == INF) continue;
		if (d[edge.v] > d[edge.u] + edge.w) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int m = 0; m < M; m++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.emplace_back(u, v, w);
	}

	if (!BellmanFord(edges)) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (d[i] == INF) printf("-1\n");
			else printf("%" PRId64 "\n", d[i]);
		}
	}
	
	return 0;
}
