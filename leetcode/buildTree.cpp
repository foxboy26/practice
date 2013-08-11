#include "leetcode.h"

class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      int len = inorder.size();
      if (len < 1) return NULL;
      if (len == 1) return new TreeNode(inorder[0]);

      for (int i = 0; i < len; i++) {
        index[inorder[i]] = i;
      }
      this->inorder = inorder;
      this->postorder = postorder;

      return buildTreeHelp(0, 0, len);
    }

    TreeNode *buildTreeHelp(int i, int p, int len) {
      if (len == 0) return NULL;

      TreeNode* root = new TreeNode(postorder[p+len-1]);
      int d = index[postorder[p+len-1]];

      root->left = buildTreeHelp(i, p, d - i);

      root->right = buildTreeHelp(d + 1, p + d - i, len - d + i - 1);

      return root;
    }
  private:
    vector<int> inorder;
    vector<int> postorder;
    map<int, int> index;
};

int main() {
  Solution s;
  vector<int> inorder;
  inorder.push_back(1);
  inorder.push_back(2);
  vector<int> postorder;
  postorder.push_back(2);
  postorder.push_back(1);

  //printVector(postorder);
  //printVector(inorder);
  TreeNode* t = s.buildTree(inorder, postorder);
  printTree(t);
  deleteTree(t);

  return 0;
}
