//
// WORDCHAIN
// Problem: https://algospot.com/judge/problem/read/WORDCHAIN
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int C, N;

vector<string> circuit;

vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> indegree, outdegree;

vector<string> GetInput() {
  vector<string> words;
  cin >> N;

  for (int n = 0; n < N; n++) {
    string input;
    cin >> input;
    words.push_back(input);
  }
  return words;
}

void MakeGraph(const vector<string>& words) {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      graph[i][j].clear();
    }
  }
  adj = vector<vector<int>>(26, vector<int>(26, 0));
  indegree = outdegree = vector<int>(26, 0);

  for (auto& word : words) {
    int u = word[0] - 'a';
    int v = word[word.length() - 1] - 'a';

    graph[u][v].push_back(word);
    adj[u][v]++;
    outdegree[u]++;
    indegree[v]++;
  }
}

void GetCircuit(vector<int>& circuit, int u) {
  for (int v = 0; v < 26; v++) {
    while (adj[u][v] > 0) {
      adj[u][v]--;
      GetCircuit(circuit, v);
    }
  }
  circuit.push_back(u);
}

vector<int> EulerCircuitOrTrail() {
  vector<int> circuit;

  for (int i = 0; i < 26; i++) {  // EulerTrail
    if (outdegree[i] == indegree[i] + 1) {
      GetCircuit(circuit, i);
      return circuit;
    }
  }

  for (int i = 0; i < 26; i++) {  // EulerCircuit
    if (outdegree[i] > 0) {
      GetCircuit(circuit, i);
      return circuit;
    }
  }

  return circuit;
}

bool CheckEuler() {
  int more_outdegree, more_indegree;
  more_outdegree = more_indegree = 0;

  for (int i = 0; i < 26; i++) {
    int delta = outdegree[i] - indegree[i];
    if (delta > 1 || delta < -1) return false;
    if (delta == 1)
      more_outdegree++;
    else if (delta == -1)
      more_indegree++;
  }

  return (more_outdegree == 1 && more_indegree == 1) ||
         (more_outdegree == 0 && more_indegree == 0);
}

void solve() {
  vector<string> words = GetInput();
  MakeGraph(words);

  if (!CheckEuler()) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<int> circuit = EulerCircuitOrTrail();
  if (circuit.size() != words.size() + 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  reverse(circuit.begin(), circuit.end());
  for (int i = 0; i < circuit.size() - 1; i++) {
    int u = circuit[i];
    int v = circuit[i + 1];

    cout << graph[u][v].back() << " ";
    graph[u][v].pop_back();
  }
  cout << endl;
}

int main() {
  cin >> C;
  for (int c = 0; c < C; c++) solve();

  return 0;
}
