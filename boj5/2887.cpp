//
// 행성 터널
// Link: https://www.acmicpc.net/problem/2887
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cinttypes>

using namespace std;

int N;

struct Edge {
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	int u, v, w;
};

struct Node {
	Node(int _id, int _w) : id(_id), w(_w) {}
	int id, w;
};

vector<Edge> edges;
vector<Node> vx;
vector<Node> vy;
vector<Node> vz;
vector<int> parent;

int Abs(int x) { return x < 0 ? -x : x; }
int Min(int x, int y) { return x < y ? x : y; }

void Preprocess(vector<Node>& vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		int value = Abs(vec[i].w - vec[i + 1].w);
		edges.emplace_back(vec[i].id, vec[i + 1].id, value);
	}
}

bool Compare(Node& x, Node& y) { return x.w < y.w; }
bool Compare2(Edge& x, Edge& y) {	return x.w < y.w; }

int GetParent(int child) {
	if (parent[child] == -1) return child;
	parent[child] = GetParent(parent[child]);
	return parent[child];
}

int main() {
	scanf("%d", &N);
	edges.reserve(N * 3);
	parent = vector<int>(N, -1);
	vx.reserve(N);
	vy.reserve(N);
	vz.reserve(N);

	for (int n = 0; n < N; n++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		vx.emplace_back(n, x);
		vy.emplace_back(n, y);
		vz.emplace_back(n, z);
	}

	sort(vx.begin(), vx.end(), Compare);
	sort(vy.begin(), vy.end(), Compare);
	sort(vz.begin(), vz.end(), Compare);

	Preprocess(vx);
	Preprocess(vy);
	Preprocess(vz);

	sort(edges.begin(), edges.end(), Compare2);

	int edge_count = 0;
	int64_t weight_sum = 0;
	for (auto& edge : edges) {
		int parent_u = GetParent(edge.u);
		int parent_v = GetParent(edge.v);
		if (parent_u != parent_v) {
			int smaller = parent_u < parent_v ? parent_u : parent_v;
			int bigger = parent_u + parent_v - smaller;
			parent[bigger] = smaller;
			weight_sum += edge.w;
			edge_count++;
			if (edge_count == N - 1) break;
		}
	}

	printf("%" PRId64 "\n", weight_sum);

	return 0;
}
