// 별자리 만들기
// https://www.acmicpc.net/problem/4386

#include <math.h>
#include <stdio.h>

#include <set>
#include <utility>
#include <vector>

using namespace std;

constexpr double kInf = 987654321;

int N;
double x, y;

vector<pair<double, double>> points;
double adj[100][100];

double Pytagoras(pair<double, double>& a, pair<double, double>& b) {
  double dx = a.first - b.first;
  double dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

double Solve() {
  double dist_sum = 0.0;

  set<int> include_set;
  include_set.insert(0);

  while (include_set.size() < N) {
    double min_dist = kInf;
    int next = -1;
    for (auto u : include_set) {
      for (int v = 0; v < N; v++) {
        if (u == v || include_set.find(v) != include_set.end()) continue;

        if (adj[u][v] < min_dist) {
          min_dist = adj[u][v];
          next = v;
        }
      }
    }
    if (next == -1) continue;

    dist_sum += min_dist;
    include_set.insert(next);
  }

  return dist_sum;
}

int main() {
  scanf("%d", &N);
  if (N == 1) {
    printf("%0.2lf\n", 0.0);
    return 0;
  }

  for (int n = 0; n < N; n++) {
    scanf("%lf%lf", &x, &y);
    points.push_back(make_pair(x, y));
  }

  for (int u = 0; u < points.size(); u++) {
    for (int v = 0; v < points.size(); v++) {
      if (u == v)
        adj[u][v] = adj[v][u] = kInf;
      else
        adj[u][v] = adj[v][u] = Pytagoras(points[u], points[v]);
    }
  }

  printf("%0.2lf\n", Solve());
  return 0;
}
