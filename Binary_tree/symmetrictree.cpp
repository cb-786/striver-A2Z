 bool lefty = true;
    bool righty = true;
    bool symm(TreeNode *root1,TreeNode *root2) {
         
         if(root1==NULL && root2!=NULL) {
            return false;
         }

         if(root2==NULL && root1!=NULL) {
            return false;
         }

         

        if(root1==NULL && root2==NULL) {
            return true;
        }

        if(root1->val != root2->val) {
            return false;
        }
 
        lefty = symm(root1->left,root2->right);
        if(lefty==false) return false;
        righty = symm(root1->right,root2->left);
       
        return (lefty && righty);

    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
       return symm(root->left,root->right);
    }