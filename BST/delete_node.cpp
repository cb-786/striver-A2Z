int minValue(TreeNode* root) {

        if(root==NULL) return NULL;

        int ans = INT_MAX;
        while(root!=NULL) {
            ans = min(root->val,ans);
            root=root->left;
        }
        
        return ans;
    }



    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key) {
             if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
             }

             if(root->left == NULL && root->right !=NULL) {
                TreeNode *child = root->right;
                delete root;
                return child;
             }

              if(root->left != NULL && root->right ==NULL) {
                TreeNode *child = root->left;
                delete root;
                return child;
             }

             if(root->left!=NULL && root->right!=NULL) {
                int mi = minValue(root->right);
                 root->val = mi;
                 root->right = deleteNode(root->right,mi);
                 return root;
             }
        }
     
        else if(root->val>key) root->left = deleteNode(root->left,key);

        else  root->right = deleteNode(root->right,key);

        return root;
    }