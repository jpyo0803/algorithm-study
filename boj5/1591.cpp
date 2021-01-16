//
// 수열 복원
// Link: https://www.acmicpc.net/problem/1591
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, M;

vector<int> circuit;
vector<int> indegree, outdegree;
vector<vector<int>> adj;

map<vector<int>, int> seq2order;
map<int, vector<int>> order2seq;

void Dfs(int u) {
	for (int v = 0; v < N; v++) {
		while (adj[u][v] > 0) {
			adj[u][v]--;
			Dfs(v);
		}
	}
	circuit.push_back(u);
}

void GetEulerCircuitOrTrail() {
	for (int i = 0; i < N; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			Dfs(i);
			return;
		}
	}

	for (int i = 0; i < N; i++) {
		if (outdegree[i] > 0) {
			Dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;

	indegree = outdegree = vector<int>(N, 0);
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	
	int order = 0;
	for (int i = 0; i < N - M + 1; i++) {
		vector<int> f, b;
		for (int m = 0; m < M; m++) {
			int num;
			cin >> num;
			if (m != M - 1) f.push_back(num); 
			if (m != 0) b.push_back(num);
		}
		if (seq2order.count(f) == 0) {
			seq2order[f] = order;
			order2seq[order] = f;
			order++;
		}
		if (seq2order.count(b) == 0) {
			seq2order[b] = order;
			order2seq[order] = b;
			order++;
		}
		int u = seq2order[f];
		int v = seq2order[b];
		adj[u][v]++;
		outdegree[u]++;
		indegree[v]++;	
	}

	GetEulerCircuitOrTrail();
	reverse(circuit.begin(), circuit.end());
	for (auto x : order2seq[circuit[0]]) cout << x << " ";
	for (int i = 1; i < circuit.size(); i++) cout << order2seq[circuit[i]].back() << " ";
	cout << endl;
	return 0;
}
