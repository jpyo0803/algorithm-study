//
// FORTRESS
// Problem: https://www.algospot.com/judge/problem/read/FORTRESS
//

#include <cstdint>
#include <cstdio>
#include <vector>

using namespace std;

int C, N;

struct Circle {
  int64_t x, y, r;
};

struct TreeNode {
  Circle c;
  TreeNode* parent = nullptr;
  vector<TreeNode*> children;
};

int64_t Square(int64_t x) { return x * x; }

bool DoesAIncludeB(const Circle& c1, const Circle& c2) {
  return (Square(c1.x - c2.x) + Square(c1.y - c2.y) < Square(c1.r - c2.r)) &&
         (c1.r > c2.r);
}

void FindInsertLocation(TreeNode* ct, TreeNode* target) {
  for (int i = 0; i < ct->children.size(); i++) {
    if (DoesAIncludeB(ct->children[i]->c, target->c)) {
      FindInsertLocation(ct->children[i], target);
      return;
    }
  }

  vector<TreeNode*> new_children;
  for (int i = 0; i < ct->children.size(); i++) {
    if (DoesAIncludeB(target->c, ct->children[i]->c)) {
      new_children.push_back(ct->children[i]);
      ct->children.erase(ct->children.begin() + i);
    }
  }
  target->children = new_children;
  target->parent = ct;
  ct->children.push_back(target);
}

vector<TreeNode> tree_nodes;

int ans;

int GetTreeDiameter(TreeNode* ct) {
  if (ct == nullptr) return 0;

  int max1 = 0, max2 = 0;
  for (int i = 0; i < ct->children.size(); i++) {
    int ret = GetTreeDiameter(ct->children[i]) + 1;
    if (ret > max1) {
      max2 = max1;
      max1 = ret;
    } else if (ret > max2) {
      max2 = ret;
    }
  }
  ans = ans < max1 + max2 ? max1 + max2 : ans;
  return max1;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    tree_nodes.clear();
    ans = 0;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
      int x, y, r;
      TreeNode tmp;
      scanf("%d%d%d", &x, &y, &r);
      tmp.c.x = x;
      tmp.c.y = y;
      tmp.c.r = r;
      tree_nodes.push_back(tmp);
    }
    for (int i = 1; i < tree_nodes.size(); i++) {
      FindInsertLocation(&tree_nodes[0], &tree_nodes[i]);
    }

    GetTreeDiameter(&tree_nodes[0]);
    printf("%d\n", ans);
  }
  return 0;
}
