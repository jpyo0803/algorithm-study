//
// Prime Pair
// Link: https://www.acmicpc.net/problem/1017
//

#include <cstdio>
#include <set>
#include <vector>

using namespace std;

constexpr int kMaxValue = 1000;
constexpr int kMaxSize = 50;
int N;
int numbers[kMaxSize];
int matched_to[kMaxSize];
vector<int> adj[kMaxSize];
set<int> answers;

bool visited[kMaxSize];
bool prime_table[kMaxValue * 2];

void EratosthenesSieve() {
  int base = 2;
  while (base <= kMaxValue * 2) {
    for (int i = base * 2; i <= kMaxValue * 2; i += base) {
      prime_table[i] = true;
    }
    while (++base <= kMaxValue * 2) {
      if (!prime_table[base]) break;
    }
  }
}

bool IsPrime(int candidate) { return !prime_table[candidate]; }

bool DFS(int a) {
  if (visited[a]) return false;
  visited[a] = true;

  for (auto& b : adj[a]) {
    if (matched_to[b] == -1 || DFS(matched_to[b])) {
      matched_to[b] = a;
      return true;
    }
  }
  return false;
}

int main() {
  EratosthenesSieve();
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (IsPrime(numbers[i] + numbers[j])) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  for (auto& b : adj[0]) {
    for (int i = 0; i < N; i++) matched_to[i] = -1;
    matched_to[b] = 0;
    int matched_count = 1;
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < N; j++) visited[j] = false;
      visited[0] = true;
      if (DFS(i)) matched_count++;
    }
    if (matched_count == N) answers.insert(numbers[b]);
  }

  if (answers.size() == 0)
    printf("-1");
  else {
    for (auto& answer : answers) {
      printf("%d ", answer);
    }
  }

  return 0;
}
