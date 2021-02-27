//
// ROUTING
// Problem: https://www.algospot.com/judge/problem/read/ROUTING
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

using namespace std;

constexpr double INF = std::numeric_limits<double>::max();

int C, N, M;
vector<double> d;
vector<map<int, double>> adj;

double Routing(int s) {
	priority_queue<pair<double, int>> pq;
	d[s] = 1.0;
	pq.push(make_pair(1.0, s));

	while (!pq.empty()) {
		auto info = pq.top(); pq.pop();
		double cost = -info.first;
		int u = info.second;

		if (d[u] < cost) continue;

		for (auto const& x : adj[u]) {
			int v = x.first;
			double w = x.second;
			if (d[u] * w < d[v]) {
				d[v] = d[u] * w;
				pq.push(make_pair(-d[v], v));
			}
		}
	}
	return d[N - 1];
}

int main() {
	cout << fixed;
	cout.precision(10);

	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N >> M;
		d = vector<double>(N, INF);
		adj = vector<map<int, double>>(N);
		for (int m = 0; m < M; m++) {
			int u, v;
			double w;
			cin >> u >> v >> w;
			if (adj[u].count(v) < 1) adj[u][v] = w;
			else adj[u][v] = w < adj[u][v] ? w : adj[u][v];
			if (adj[v].count(u) < 1) adj[v][u] = w;
			else adj[v][w] = w < adj[v][u] ? w : adj[v][u];
		}
		cout << Routing(0) << std::endl;
	}
	
	return 0;
}
