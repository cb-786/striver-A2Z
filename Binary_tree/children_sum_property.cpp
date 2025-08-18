bool rec(TreeNode *root) {
        
        if(root==NULL) return true;
        
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        
        bool left = rec(root->left);
        bool right = rec(root->right);
        
        int l = (root->left==NULL) ? 0:root->left->val;
        int r = (root->right==NULL) ? 0: root->right->val;
        
        if(l+r != root->val) return false;
        
        return (left && right);
    }
    
    bool checkTree(TreeNode* root) {
        return rec(root);
    }