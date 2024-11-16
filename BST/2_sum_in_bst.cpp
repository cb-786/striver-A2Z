TreeNode *temp;
   bool ans = false;
   bool is2(TreeNode *root,int c,int k) {
    if(root==NULL) return ans;

    if(c!=root->val)
    if(root->val+c == k) {
        ans = true;
        return ans;
    }

    bool lefty = is2(root->left,c,k);
    if(lefty) {
        ans = true;
        return ans;
    }
    bool righty = is2(root->right,c,k);

    return (lefty || righty);
   }

    bool rec(TreeNode* root, int k) {
        if(root==NULL) return ans;

       bool lefty = rec(root->left,k);
       if(lefty == true) {
        ans = true;
        return ans;
       }
       
        bool righty =  rec(root->right,k);

        return is2(temp,root->val,k);

        return (lefty || righty);
    }
    
    bool findTarget(TreeNode* root, int k) {
      temp = root;
       return rec(temp,k);
    }