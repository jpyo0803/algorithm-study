//
// Printer Queue
// Link: https://www.acmicpc.net/problem/1966
//

#include <cstdio>
#include <deque>

using namespace std;
deque<pair<int, int>> documents;
int T, N, M, p;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &N, &M);
    documents.clear();
    for (int i = 0; i < N; i++) {
      scanf("%d", &p);
      documents.emplace_back(i, p);
    }

    int nth = 1;
    while (true) {
      auto first_document = documents.front();
      documents.pop_front();
      bool pass = true;
      for (auto& other : documents) {
        if (first_document.second < other.second) {
          documents.push_back(first_document);
          pass = false;
          break;
        }
      }
      if (pass) {
        if (first_document.first == M) {
          printf("%d\n", nth);
          break;
        }
        nth++;
      }
    }
  }
  return 0;
}