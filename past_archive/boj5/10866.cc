//
// 덱
// Link: https://www.acmicpc.net/problem/10866
//

#include <iostream>
#include <string>

using namespace std;

int N;

struct Node {
  Node(int _val) : val(_val), before(nullptr), after(nullptr) {}
  int val;
  Node* before;
  Node* after;
};

class Deque {
 public:
  Deque() : head(nullptr), tail(nullptr), size(0) {}
  void PushFront(int x) {
    Node* new_node = GetNewNode(x);
    if (size == 0) {
      tail = new_node;
    } else {
      head->before = new_node;
      new_node->after = head;
    }
    head = new_node;
    size++;
  }

  void PushBack(int x) {
    Node* new_node = GetNewNode(x);
    if (size == 0) {
      head = new_node;
    } else {
      tail->after = new_node;
      new_node->before = tail;
    }
    tail = new_node;
    size++;
  }

  int PopFront() {
    int ret = Front();
    if (ret != -1) {
      Node* temp = head;
      head = head->after;
      if (head)
        head->before = nullptr;
      else
        tail = nullptr;
      DeleteNode(temp);
      size--;
    }
    return ret;
  }

  int PopBack() {
    int ret = Back();
    if (ret != -1) {
      Node* temp = tail;
      tail = tail->before;
      if (tail)
        tail->after = nullptr;
      else
        head = nullptr;
      DeleteNode(temp);
      size--;
    }
    return ret;
  }

  int Size() { return size; }

  bool Empty() { return size == 0; }

  int Front() { return (size == 0 ? -1 : head->val); }

  int Back() { return (size == 0 ? -1 : tail->val); }

 private:
  Node* GetNewNode(int x) { return new Node(x); }
  void DeleteNode(Node* n) {
    if (n) delete n;
  }

  Node *head, *tail;
  int size;
};

Deque dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int n = 0; n < N; n++) {
    string op;
    cin >> op;
    int operand;
    if (op == "push_back" || op == "push_front") {
      cin >> operand;
    }
    if (op == "push_front")
      dq.PushFront(operand);
    else if (op == "push_back")
      dq.PushBack(operand);
    else if (op == "pop_front")
      cout << dq.PopFront() << endl;
    else if (op == "pop_back")
      cout << dq.PopBack() << endl;
    else if (op == "size")
      cout << dq.Size() << endl;
    else if (op == "empty")
      cout << dq.Empty() << endl;
    else if (op == "front")
      cout << dq.Front() << endl;
    else if (op == "back")
      cout << dq.Back() << endl;
  }
  return 0;
}