//
// DICTIONARY
// Link: https://www.algospot.com/judge/problem/read/DICTIONARY
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C, N;

vector<string> words;
vector<char> answers;

bool graph[26][26];
bool visited[26];
bool visited2[26];
bool cycle_detected = false;

void Dfs(int u) {
  if (cycle_detected) return;
  visited[u] = visited2[u] = true;
  for (int v = 0; v < 26; v++) {
    if (graph[u][v]) {
      if (visited2[v]) {
        cycle_detected = true;
        return;
      }
      if (!visited[v]) Dfs(v);
    }
  }
  visited2[u] = false;
  answers.push_back(u + 'a');
}

void DfsAll() {
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < 26; j++) visited2[j] = false;
    if (!visited[i]) Dfs(i);
  }
}

int main() {
  cin >> C;
  for (int c = 0; c < C; c++) {
    cin >> N;
    for (int n = 0; n < N; n++) {
      string input;
      cin >> input;
      words.push_back(input);
    }

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        graph[i][j] = false;
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      int j = i + 1;
      int k = 0;
      while (k < words[i].length() && k < words[j].length()) {
        if (words[i][k] != words[j][k]) {
          graph[words[i][k] - 'a'][words[j][k] - 'a'] = true;
          break;
        }
        k++;
      }
    }

    for (int i = 0; i < 26; i++) visited[i] = false;
    DfsAll();

    if (cycle_detected) {
      cout << "INVALID HYPOTHESIS" << endl;
    } else {
      for (auto rev_it = answers.rbegin(); rev_it != answers.rend(); rev_it++) {
        cout << *rev_it; 
      }
      cout << endl;
    }

    cycle_detected = false;
    answers.clear();
    words.clear();
  }
  return 0;
}