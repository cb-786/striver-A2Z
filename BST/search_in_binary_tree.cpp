TreeNode *ans;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;

        if(root->val == val) {
            ans = root;
            return root;
        }

        

        if(root->val>val) searchBST(root->left,val);

        if(root->val<val) searchBST(root->right,val);

        return ans;

    }