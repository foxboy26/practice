#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int x, TreeNode *left = NULL, TreeNode *right = NULL) : val(x), left(left), right(right) {}
};

void deleteBST(TreeNode *&root)
{
    if (root)
    {
        deleteBST(root->left);
        deleteBST(root->right);
        delete root;
        root = NULL;
    }
}

int depthRecursion(TreeNode *root)
{
    if (!root) return 0;

    int leftDepth = depthRecursion(root->left);
    int rightDepth = depthRecursion(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int depth(TreeNode *root)
{
    if (!root) return 0;
    stack<TreeNode*> s;
    TreeNode* t;
    int d = 0;

    s.push(root);
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        if (t)
        {
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        int size = s.size();
        d = max(d, size);
    }

    return d;
}

bool search(TreeNode *root, int x)
{
    while (root)
    {
        if (root->val == x) return true;
        else if (x < root->val) root = root->left;
        else root = root->right;
    }

    return false;
}

void preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void preorderNonrecursive(TreeNode *root)
{
    stack<TreeNode*> s;

    s.push(root);

    TreeNode *t;
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        if (t)
        {
            cout << t->val << " ";
            s.push(t->right);
            s.push(t->left);
        }
    }
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void inorderNonrecursive(TreeNode *root)
{
    stack<TreeNode*> s;

    s.push(root);

    TreeNode *t;
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        if (t)
        {
            cout << t->val << " ";
            s.push(t->right);
            s.push(t->left);
        }
    }
}

void postorder(TreeNode *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    TreeNode *bst = new TreeNode(6,
                        new TreeNode(3,
                            new TreeNode(1),
                            new TreeNode(5)),
                        new TreeNode(11,
                            new TreeNode(9,
                                new TreeNode(7),
                                new TreeNode(10))));
    TreeNode *bst2 = new TreeNode(4);

    cout << search(bst, 10) << endl;

    cout << "Depth: " << depth(bst2) << endl;
    cout << "Depth(recursion): " << depthRecursion(bst2) << endl;

    preorder(bst); cout << endl;
    preorderNonrecursive(bst); cout << endl;

    inorder(bst); cout << endl;

    postorder(bst); cout << endl;

    deleteBST(bst);

    return 0;
}
