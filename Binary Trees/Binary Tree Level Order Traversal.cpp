// 100% faster solution

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> currLevel;
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size() != 0)
    {
        if (pendingNodes.front() != NULL)
        {
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            currLevel.push_back(front->val);
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
        else
        {
            pendingNodes.pop();
            if (pendingNodes.size() != 0)
            {
                ans.push_back(currLevel);
                currLevel.clear();
                pendingNodes.push(NULL);
            }
            else
            {
                ans.push_back(currLevel);
                continue;
            }
        }
    }
    return ans;
}
