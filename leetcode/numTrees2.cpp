vector<TreeNode *> generateTrees(int n) {
  return generateTreesHelp(1, n);
}

vector<TreeNode*> generateTreesHelp(int l, int r) {

  vector<TreeNode*> trees;

  if (r < l)
  {
    trees.push_back(NULL);
    return trees;
  }

  for (int i = l; i <= r; i++)
  {
    vector<TreeNode*> left = generateTreesHelp(l, i - 1);
    vector<TreeNode*> right = generateTreesHelp(i + 1, r);
    for (int j = 0; j < left.size(); j++)
    {
      for (int k = 0; k < right.size(); k++)
      {
        TreeNode* r = new TreeNode(i);
        r->left = left[j];
        r->right = right[k];
        trees.push_back(r);
      }
    }
  }

  return trees;
}
