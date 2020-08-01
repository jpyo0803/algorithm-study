//
// 열혈강호 2
// Link: https://www.acmicpc.net/problem/11376
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMaxSize = 1000;
int N, M, num_jobs, job;
vector<int> jobs_can_do[kMaxSize + 1];
int assigned_to[kMaxSize + 1];
bool visited[kMaxSize + 1];

bool DFS(int employee) {
  if (visited[employee]) return false;
  visited[employee] = true;

  for (auto &job : jobs_can_do[employee]) {
    if (assigned_to[job] == -1 || DFS(assigned_to[job])) {
      assigned_to[job] = employee;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) assigned_to[i] = -1;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &num_jobs);
    for (int j = 0; j < num_jobs; j++) {
      scanf("%d", &job);
      jobs_can_do[i].push_back(job);
    }
  }

  int job_done_count = 0;

  for (int i = 1; i <= N; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 1; j <= N; j++) visited[j] = false;
      if (DFS(i)) job_done_count++;
    }
  }

  printf("%d\n", job_done_count);
  return 0;
}
