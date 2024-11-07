 bool sum1(TreeNode *root,int target,int sum) {

        if(root==NULL) return false;
       sum+=root->val;
          if(root->left==NULL && root->right == NULL) {
            if(sum == target) {
                return true;
            }
            else {
                return false;
            }
          }

         

          
 
     
         bool left =  sum1(root->left,target,sum);
         bool right =  sum1(root->right,target,sum);

          return left||right;
    }



    bool hasPathSum(TreeNode* root, int targetSum) {

       

        
        int sum = 0;
        return sum1(root,targetSum,sum);
    }