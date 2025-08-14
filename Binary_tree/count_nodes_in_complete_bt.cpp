void count(TreeNode* root, int idx, int &ans) {
        if (!root) return;
        ans = max(ans, idx);
        count(root->right, 2 * idx + 1, ans);
        count(root->left, 2 * idx, ans);
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        count(root, 1, ans);
        return ans;
    }