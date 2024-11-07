int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
        int ans = max(lefth,righth) +1;
        return ans;
    }