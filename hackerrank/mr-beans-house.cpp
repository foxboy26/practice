#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int xMin, xMax, yMin, yMax;

struct Pos {
  int x, y;
  Pos(int x, int y) : x(x), y(y) {}
};

struct TreeNode {
  Pos val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(Pos pos) : val(pos), left(NULL), right(NULL) {}
};

void insert(TreeNode*& root, Pos p, int split) {
  if (root == NULL) {
    root = new TreeNode(p);
  } else {
    int val, curVal;
    if (split == 1) {
      val = p.x;
      curVal = root->val.x;
    } else {
      val = p.y;
      curVal = root->val.y;
    }

    if (val < curVal) {
      insert(root->left, p, 1 - split);
    } else {
      insert(root->right, p, 1 - split);
    }
  }
}

void query(TreeNode* root, Pos p, int split) {
  if (root != NULL) {
    int val, curVal;
    if (split == 1) {
      val = p.x;
      curVal = root->val.x;
    } else {
      val = p.y;
      curVal = root->val.y;
    }

    if (val < curVal) {
      if (split == 1) {
        xMax = curVal;
      } else {
        yMax = curVal;
      }
      query(root->left, p, 1-split);
    } else {
      if (split == 1) {
        xMin = curVal;
      } else {
        yMin = curVal;
      }
      query(root->right, p, 1-split);
    }
  }
}

void printHelp(TreeNode* root, int level) {
  if (root == NULL) return;

  for (int i = 0; i < level * 2; i++) {
    cout << " ";
  }
  cout << root->val.x << ", " << root->val.y << endl;
  printHelp(root->left, level + 1);
  printHelp(root->right, level + 1);
}

void print(TreeNode* root) {
  printHelp(root, 0);
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int W, H, N, Q;
  cin >> W >> H >> N >> Q;

  int x, y;
  TreeNode* root = NULL;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    insert(root, Pos(x, y), 0);
  } 

  print(root);

  int res = 0;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y;
    xMin = 0; xMax = W;
    yMin = 0; yMax = H;
    query(root, Pos(x, y), 0);
    res = min(min(x - xMin, xMax - x), min(y - yMin, yMax - y));
    cout << "xMin: " << xMin << " xMax: " << xMax << " yMin: " << yMin << " yMax: " << yMax << endl;
    cout << res * 2 << endl;
  }

  return 0;
}
