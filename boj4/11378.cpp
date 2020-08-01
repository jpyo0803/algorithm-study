//
// 열혈강호 4
// Link: https://www.acmicpc.net/problem/11378
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMaxSize = 1000;
int assigned_to[kMaxSize + 1];
int N, M, K, num_jobs, job;
vector<int> jobs_can_do[kMaxSize + 1];
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
  scanf("%d%d%d", &N, &M, &K);
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
    for (int j = 1; j <= N; j++) visited[j] = false;
    if (DFS(i)) {
      job_done_count++;
    }
  }

  bool flag = true;
  while (K > 0 && flag) {
    flag = false;
    for (int i = 1; i <= N && K > 0; i++) {
      for (int j = 1; j <= N; j++) visited[j] = false;
      if (DFS(i)) {
        flag = true;
        job_done_count++;
        K--;
        break;
      }
    }
  }

  printf("%d\n", job_done_count);
  return 0;
}