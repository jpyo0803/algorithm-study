/*
  This is binary search tree with augmentation

  Assuming the tree is fairly well balanced
  searching for a element takes O(log(n))
  insertion also takes O(log(n))
*/

#include <iostream>

using namespace std;

class Node {
public:
  int key;
  int size;
  Node *parent, *left, *right;
};

Node* newNode(int _key){
  Node* tmp = new Node();
  tmp->key = _key;
  tmp->size = 1;
  tmp->left = tmp->right = nullptr;
  return tmp;
}

void insert(Node* curr, int key) {
  bool go_left = true;
  if (curr->key < key) go_left = false;

  if (go_left) {
    curr->size++;
    if (curr->left == nullptr) {
      curr->left = newNode(key);
    } else {
      insert(curr->left, key);
    }
  } else {
    curr->size++;
    if (curr->right == nullptr) {
      curr->right = newNode(key);
    } else {
      insert(curr->right, key);
    }
  }
}

void remove(Node* curr, int key) {
  if (curr != nullptr) {
    if (curr->key < key) {
      remove(curr->right, key);
    } else if (curr->key > key) {
      remove(curr->left, key);
    } else {

    }
  }
}

void traverse(Node* curr) {
  if (curr != nullptr) {
    traverse(curr->left);
    cout << curr->key << " / " << curr->size << "\n";
    traverse(curr->right);
  }
}

bool search(Node* curr, int key) {
  if (curr == nullptr) {
    return false;
  } else {
    if (curr->key == key) {
      return true;
    } else {
      if (curr->key < key) {
        return search(curr->right, key);
      } else {
        return search(curr->left, key);
      }
    }
  }
}


void find_rank(Node* curr, int key, int& sum) {
  if (curr != nullptr) {
    if (curr->key < key) {
      sum++;
      if (curr->left != nullptr) {
        sum += curr->left->size;
      }
      find_rank(curr->right, key, sum);
    } else if (curr->key > key) {
      find_rank(curr->left, key, sum);
    } else {
      if (curr->left != nullptr) {
        sum += curr->left->size;
      }
      sum++;
    }
  }
}

int curr_cnt = 0;

void nth_largest(Node* curr, int nth) {
  if (curr != nullptr) {
    nth_largest(curr->right, nth);
    curr_cnt++;
    if (nth == curr_cnt) {
      cout << nth << "-th value : " << curr->key << "\n";
    }
    nth_largest(curr->left, nth);
  }
}


int main() {
  Node* root = newNode(50);

  insert(root, 25);
  insert(root, 75);
  insert(root, 12);
  insert(root, 88);
  insert(root, 6);
  insert(root, 18);
  insert(root, 80);
  insert(root, 95);
  insert(root, 60);
  insert(root, 55);

  traverse(root);

  cout << "\n\n";

  if (search(root, 80)) {
    cout << "found\n";
  } else {
    cout << "not found\n";
  }

  if (search(root, 23)) {
    cout << "found\n";
  } else {
    cout << "not found\n";
  }

  if (search(root, 55)) {
    cout << "found\n";
  } else {
    cout << "not found\n";
  }

/*
        50
      /    \
     25    75
    /     /  \
  12     60   88
  /\     /    / \
 6 18   55    80  95

*/

  int sum = 0;
  find_rank(root, 55, sum);
  cout << "rank : " << sum << "\n\n";

  curr_cnt = 0;
  nth_largest(root, 8);

  return 0;
}