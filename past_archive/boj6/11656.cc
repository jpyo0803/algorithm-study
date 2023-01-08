// 접미사 배열
// https://www.acmicpc.net/problem/11656

#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

using namespace std;

char S[1001];

int Min(int x, int y) { return x < y ? x : y; }

bool IsSmaller(const string& s1, const string& s2) {
  int len = Min(s1.size(), s2.size());
  for (int i = 0; i < len; i++) {
    if (s1[i] == s2[i]) continue;
    return s1[i] < s2[i];
  }
  return s1.size() < s2.size();
}

int Partition(vector<string>& vec, int l, int r) {
  int offset = vec[r].size() % (r - l + 1);
  swap(vec[l + offset], vec[r]);
  int i = l;
  for (int j = l; j < r; j++) {
    if (IsSmaller(vec[j], vec[r])) {
      swap(vec[i], vec[j]);
      i++;
    }
  }
  swap(vec[i], vec[r]);
  return i;
}

void Quicksort(vector<string>& vec, int l, int r) {
  if (l >= r) return;
  int pivot = Partition(vec, l, r);
  Quicksort(vec, l, pivot - 1);
  Quicksort(vec, pivot + 1, r);
}

vector<string> Solve(const char* s) {
  vector<string> ans;
  for (int i = 0; i < strlen(s); i++) ans.push_back(s + i);
  Quicksort(ans, 0, ans.size() - 1);
  return ans;
}

int main() {
  scanf("%s", S);
  auto ans = Solve(S);
  for (auto& e : ans) printf("%s\n", e.c_str());
  return 0;
}
