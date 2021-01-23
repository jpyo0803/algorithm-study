//
// 2-SAT - 3
// Link: https://www.acmicpc.net/problem/11280
//

#include <cstdio>
#include <stack>
#include <vector>
#include <set>

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }

set<int> adj[20001];
int discovered[20001];
int scc_id[20001];
stack<int> stk;
int N, M, count, scc_count;

int TarjanSCC(int u) {
	int ret = discovered[u] = count++;
	stk.push(u);

	for (auto v : adj[u]) {
		if (discovered[v] == -1) {
			ret = Min(ret, TarjanSCC(v));
		} else if (scc_id[v] == -1) {
			ret = Min(ret, discovered[v]);
		}
	}

	if (ret == discovered[u]) {
		while (true) {
			int t = stk.top(); stk.pop();	
			scc_id[t] = scc_count;
			if (t == u) break;	
		}
		scc_count++;
	}
	return ret;
}

int main() {
	count = scc_count = 0;
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= 2 * N; i++) discovered[i] = scc_id[i] = -1;

	for (int m = 0; m < M; m++) {
		int xi, xj;
		scanf("%d%d", &xi, &xj);
		if (xi > 0) {
			if (xj > 0) { // xi > 0, xj > 0
				adj[xi + N].insert(xj); // -xi -> xj
				adj[xj + N].insert(xi); // -xj -> xi
			} else { // xi > 0, xj < 0
				adj[xi + N].insert(Abs(xj) + N); // -xi -> -xj
				adj[Abs(xj)].insert(xi); // check
			}	
		} else {
			if (xj > 0) { // xi < 0, xj > 0
				adj[Abs(xi)].insert(xj);
				adj[xj + N].insert(Abs(xi) + N);
			} else {
				adj[Abs(xi)].insert(Abs(xj) + N);
				adj[Abs(xj)].insert(Abs(xi) + N);
			}
		}
	}
	for (int u = 1; u <= 2 * N; u++) {
		if (discovered[u] == -1) TarjanSCC(u);
	}

	for (int i = 1; i <= N; i++) {
		if (scc_id[i] == scc_id[i + N]) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");

	return 0;
}

