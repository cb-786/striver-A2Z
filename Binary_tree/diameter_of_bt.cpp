int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
        int ans = max(lefth,righth) +1;
        return ans;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        return max(op1,max(op2,op3));

        


    }