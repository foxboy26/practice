#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class BinaryTree {
  public:
    BinaryTree() { root = NULL; }
    BinaryTree(const vector<int>& data) {
      root = createTree(data);
    }
    ~BinaryTree() {
      deleteTree(root);
    }

    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    void PrintInOrderIterative();
    void PrintPreOrderIterative();
    void PrintPostOrderIterative();
 private:
    TreeNode* root;

    /* utilities */
    void createTree(const vector<int>& data);
    void printTree();
    void printTreeHelp(TreeNode* root, int level);
    void deleteTree(TreeNode* root);

    void _PrintInOrder(TreeNode* root);
    void _PrintPreOrder(TreeNode* root);
    void _PrintPostOrder(TreeNode* root);
    void _PrintInOrderIterative(TreeNode* root);
    void _PrintPreOrderIterative(TreeNode* root);
    void _PrintPostOrderIterative(TreeNode* root);

  friend ostream& operator<< (ostream& out, TreeNode* t);
}

ostream& operator<< (ostream& out, const BinaryTree& tree) {
  tree.printTree();
  return out;
}

int main()
{
  vector<int> data = {1, 2, 3};
  BinaryTree root = BinaryTree(data);
  //root.PrintInOrder();
  //root.PrintInOrder();
  //root.PrintPreOrder();
  //root.PrintInOrder();
  //root.PrintPostOrder();
  //root.PrintInOrder();
  cout << root << endl;
  return 0;
}

void inOrder(TreeNode* root) {
  if (root != NULL) {
    inOrder(root->left);
    cout << root-> val << " ";
    inOrder(root->right);
  }
}

void inOrderIterative(TreeNode* root) {

}

void preOrder(TreeNode* root) {
  if (root != NULL) {
    cout << root-> val << " ";
  }
  inOrder(root->left);
  inOrder(root->right);
}

void preOrderIterative(TreeNode* root) {
}

void postOrder(TreeNode* root) {
  if (root != NULL) {
    inOrder(root->left);
    inOrder(root->right);
    cout << root-> val << " ";
  }
}

void postOrderIterative(TreeNode* root) {

}

TreeNode* createTree(const vector<int>& data) {
  int len = data.size();
  if (len == 0) {
    return NULL;
  }

  TreeNode* root = new TreeNode(data[0]);
  queue<TreeNode*> q;
  q.push(root);
  for (int i = 1; i < len; i+=2) {
    TreeNode* t = q.front();
    q.pop();
    if (data[i] != '#') {
      t->left = new TreeNode(data[i]);
      q.push(t->left);
    }
    if (data[i + 1] != '#') {
      t->right = new TreeNode(data[i]);
      q.push(t->right);
    }
  }

  return root;
}

void printTree() {
  printTreeHelp(root, 0);
}

void printTreeHelp(TreeNode* root, int level) {
  if (root != NULL) {
    for (int i = 0; i < level; i++) {
      cout << " ";
    }
    cout << root->val << endl;
    printTreeHelp(root->left, level + 2);
    printTreeHelp(root->right, level + 2);
  }
}

void deleteTree(TreeNode* root) {
  if (root != NULL) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}
