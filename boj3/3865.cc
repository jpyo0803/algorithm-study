//
// 학회원
// Link: https://www.acmicpc.net/problem/3865
//

#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
string line;

struct Node {
  Node(string& name) : group_name(name) {}
  string group_name;
  vector<std::shared_ptr<Node>> children;
};

unordered_map<string, std::shared_ptr<Node>> address_map;
unordered_set<string> count_set;

int DFS(string& curr_name) {
  int sum = 0;
  auto& curr_node = address_map[curr_name];
  for (auto& it : curr_node->children) {
    if (it->children.size() == 0) {
      if (count_set.find(it->group_name) == count_set.end()) {
        sum += 1;
        count_set.insert(it->group_name);
      }
    } else {
      if (count_set.find(it->group_name) == count_set.end()) {
        sum += DFS(it->group_name);
        count_set.insert(it->group_name);
      }
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while (N != 0) {
    address_map.clear();
    count_set.clear();
    string head;
    for (int i = 0; i < N; i++) {
      cin >> line;
      string group_name = "";
      vector<string> members;
      string buffer = "";
      int pos = 0;
      while (line[pos] != ':') {
        buffer += line[pos++];
      }
      group_name = buffer;
      pos++;
      buffer = "";
      while (true) {
        if (line[pos] == ',' || line[pos] == '.') {
          members.push_back(buffer);
          if (line[pos] == '.') break;
          pos++;
          buffer = "";
        } else {
          buffer += line[pos++];
        }
      }
      if (i == 0) {
        head = group_name;
      }
      if (address_map[group_name] == nullptr) {
        auto node = make_shared<Node>(group_name);
        address_map[group_name] = node;
      }

      for (auto& member_name : members) {
        if (address_map[member_name] == nullptr) {
          auto node = make_shared<Node>(member_name);
          address_map[member_name] = node;
        }
        auto& group_node = address_map[group_name];
        group_node->children.push_back(address_map[member_name]);
      }
    }

    printf("%d\n", DFS(head));
    cin >> N;
  }
  return 0;
}