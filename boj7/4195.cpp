// 친구 네트워크
// https://www.acmicpc.net/problem/4195

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  string name;
  int ref_count = 0;
  Node* parent = nullptr;
};

unordered_map<string, Node*> m;

int T, F;
string a, b;
vector<Node*> vec;

Node* FindRoot(Node* now) {
  if (now->parent == nullptr) {
    return now;
  }
  now->parent = FindRoot(now->parent);
  return now->parent;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> F;
    m.clear();
    for (auto x : vec) delete x;

    for (int f = 0; f < F; f++) {
      cin >> a >> b;
      int ans;
      if (m.count(a) == 0 && m.count(b) == 0) {
        Node* n_a = new Node();
        Node* n_b = new Node();
        vec.push_back(n_a);
        vec.push_back(n_b);
        n_a->name = a;
        n_b->name = b;
        n_b->parent = n_a;
        n_a->ref_count = 2;
        ans = n_a->ref_count;
        m[a] = n_a;
        m[b] = n_b;
      } else if (m.count(a) == 0) {
        Node* n_a = new Node();
        vec.push_back(n_a);
        n_a->name = a;
        n_a->parent = FindRoot(m[b]);
        n_a->parent->ref_count++;
        ans = n_a->parent->ref_count;
        m[a] = n_a;
      } else if (m.count(b) == 0) {
        Node* n_b = new Node();
        vec.push_back(n_b);
        n_b->name = b;
        n_b->parent = FindRoot(m[a]);
        n_b->parent->ref_count++;
        ans = n_b->parent->ref_count;
        m[b] = n_b;
      } else {
        Node* p_a = FindRoot(m[a]);
        Node* p_b = FindRoot(m[b]);
        if (p_a->name != p_b->name) {
          p_a->ref_count += p_b->ref_count;
          p_b->parent = p_a;
        }
        ans = p_a->ref_count;
      }
      cout << ans << "\n";
    }
  }

  return 0;
}
