// 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> completer_map;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  for (auto& e : completion) {
    ++completer_map[e];
  }
  for (auto& e : participant) {
    --completer_map[e];
    if (completer_map[e] == -1) {
      answer = e;
      break;
    }
  }
  return answer;
}