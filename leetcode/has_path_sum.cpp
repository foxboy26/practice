bool hasPathSum(TreeNode *root, int sum)
{
  if (root == NULL) return false;

  stack<TreeNode*> q;
  stack<int> q_sum;
  q.push(root);
  q_sum.push(root->val);

  TreeNode* t;
  int e;
  while (!q.empty())
  {
    t = q.top();
    q.pop();
    e = q_sum.top();
    q_sum.pop();

    if (t->left == NULL && t->right == NULL && e == sum)
      return true;
    
    if (t->left)
    {
      q.push(t->left);
      q_sum.push(e+t->left->val);
    }

    if (t->right)
    {
      q.push(t->right);
      q_sum.push(e+t->right->val);
    }
  }

  return false;
}
