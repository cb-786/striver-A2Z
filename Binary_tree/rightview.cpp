vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;  // If the tree is empty, return an empty result.

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Get the number of nodes at the current level.
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            
            // If this is the rightmost node at the current level, add it to the result.
            if (i == levelSize - 1) {
                ans.push_back(temp->val);
            }
            
            // Push the left and right children of the current node into the queue.
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }

    return ans;
}