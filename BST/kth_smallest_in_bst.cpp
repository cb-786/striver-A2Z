int r=-1;
    int ans=-1;
    int kthSmallest1(TreeNode* root, int &k) {

        if(root==NULL || k<=0) return r;

            kthSmallest1(root->left,k);
        
        r=root->val;
        k--;
        if(k==0) {
            ans=r;
            return r;
        }
            kthSmallest1(root->right,k);

        return r;
    }



    int kthSmallest(TreeNode* root, int k) {
        
    
         kthSmallest1(root,k);
         return ans;
    }