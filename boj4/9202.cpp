//
// Boggle
// Link: https://www.acmicpc.net/problem/9202
//

#include <cstdio>
#include <string>
#include <unordered_set>

using namespace std;

constexpr int ALPHABETS = 26;
constexpr int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int w, b;
char input[9];
unordered_set<string> words;
unordered_set<string> found_answers;
char board[4][4];
bool visited[4][4];

int total_score;
string longest_answer;

int ToNumber(char ch) { return ch - 'A'; }

bool InRange(int i, int j) { return (i >= 0 && i < 4 && j >= 0 && j < 4); }

bool IsBigger(const string& x, const string& y) {
  if (x.size() > y.size())
    return true;
  else if (x.size() < y.size())
    return false;

  for (int i = 0; i < x.size(); i++) {
    if (x[i] < y[i])
      return true;
    else if (x[i] > y[i])
      return false;
  }
  return false;
}
struct TrieNode {
  TrieNode* children[ALPHABETS];
  bool terminal;

  TrieNode() : terminal(false) {
    for (int i = 0; i < ALPHABETS; i++) children[i] = nullptr;
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; i++) {
      if (children[i]) delete children[i];
    }
  }

  void insert(const char* key) {
    if (*key == '\0')
      terminal = true;
    else {
      int next = ToNumber(*key);
      if (children[next] == nullptr) {
        children[next] = new TrieNode();
      }
      children[next]->insert(key + 1);
    }
  }

  void DFS(int r, int c, char* input, int length) {
    if (terminal) found_answers.insert(input);
    if (length >= 8) return;

    for (int i = 0; i < 8; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (!InRange(nr, nc)) continue;
      if (visited[nr][nc]) continue;
      int next = ToNumber(board[nr][nc]);
      if (children[next] == nullptr) continue;
      visited[nr][nc] = true;
      input[length] = board[nr][nc];
      input[length + 1] = '\0';
      children[next]->DFS(nr, nc, input, length + 1);
      visited[nr][nc] = false;
    }
  }
};

int main() {
  TrieNode* tn = new TrieNode();

  scanf("%d", &w);
  for (int i = 0; i < w; i++) {
    scanf("%s", input);
    words.insert(input);
    tn->insert(input);
  }

  scanf("%d", &b);
  for (int t = 0; t < b; t++) {
    for (int i = 0; i < 4; i++) {
      scanf("%s", input);
      for (int j = 0; j < 4; j++) board[i][j] = input[j];
    }

    found_answers.clear();

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int next = ToNumber(board[i][j]);
        if (tn->children[next] == nullptr) continue;
        visited[i][j] = true;
        input[0] = board[i][j];
        input[1] = '\0';
        tn->children[next]->DFS(i, j, input, 1);
        visited[i][j] = false;
      }
    }

    total_score = 0;
    longest_answer = "";
    for (auto& found_answer : found_answers) {
      if (IsBigger(found_answer, longest_answer)) longest_answer = found_answer;
      if (found_answer.length() >= 3 && found_answer.length() <= 4)
        total_score += 1;
      else if (found_answer.length() == 5)
        total_score += 2;
      else if (found_answer.length() == 6)
        total_score += 3;
      else if (found_answer.length() == 7)
        total_score += 5;
      else if (found_answer.length() == 8)
        total_score += 11;
    }

    printf("%d %s %d\n", total_score, longest_answer.c_str(),
           found_answers.size());
  }
  return 0;
}
