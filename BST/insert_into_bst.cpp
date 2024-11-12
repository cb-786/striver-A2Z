TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode *newnode = new TreeNode(val);
            root = newnode;
            return root;
        }


        if(root->val<val) {
            if(root->right == NULL) {
            TreeNode *newnode = new TreeNode(val);
            root->right = newnode;
            return root;
            }
            insertIntoBST(root->right,val);
        }

        else {
            if(root->left == NULL) {
            TreeNode *newnode = new TreeNode(val);
            root->left = newnode;
            return root;
            }
            insertIntoBST(root->left,val);
        }

        return root;
    }