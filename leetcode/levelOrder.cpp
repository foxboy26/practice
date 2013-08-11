vector<vector<int> > levelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > res;
        
    if (root == NULL) {
        return res;
    }
        
    int nodesInCurLevel = 0;
    int nodesInNextLevel = 0;
        
    vector<int> levelNodes;
        
    queue<TreeNode*> q;
    q.push(root);
    nodesInCurLevel++;
    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        nodesInCurLevel--;

        levelNodes.push_back(t->val);

        if (t->left) {
            q.push(t->left);
            nodesInNextLevel++;
        }

        if (t->right) {
            q.push(t->right);
            nodesInNextLevel++;
        }
            
        if (nodesInCurLevel == 0) {
            res.push_back(levelNodes);
            levelNodes.clear();

            nodesInCurLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}
