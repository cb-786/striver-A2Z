int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
        int ans = max(lefth,righth) +1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
       
        if(root==NULL) {
            return true;
        }
        
         bool lefth = isBalanced(root->left);
         bool righth = isBalanced(root->right);

         bool curr = (abs(maxDepth(root->left) - maxDepth(root->right)) <=1);

         if(curr && lefth && righth) {
                return true;
         }

         else {
            return false;
         }
    }