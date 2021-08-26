// 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> type_count;

int solution(vector<vector<string>> clothes) {
  int answer = 0;
  for (auto& a : clothes) {
    ++type_count[a[1]];
  }

  answer = 1;
  for (auto& a : type_count) {
    answer *= a.second + 1;
  }

  return answer - 1;
}