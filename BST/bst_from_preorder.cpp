TreeNode* helper(vector<int>& preorder, int start, int end){
        // bc
        if(start>end) return NULL;

        int r_s;

        for(int i=start; i<=end;i++){
            if(preorder[i]>preorder[start]){
                r_s= i;
                break;
            }
        }
        int l_s=start+1;
        int l_e= r_s-1;
        int r_e=end;
        TreeNode* root= new TreeNode(preorder[start]);
        root->left= helper(preorder, l_s,l_e);
        root->right= helper(preorder, r_s,r_e);
        return root;

        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);

        
    }