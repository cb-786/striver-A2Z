/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int MOD = 1e9+7;
    int rec(TreeNode *root) {
        
        if(root->left == NULL && root ->right == NULL) {
            return root->val;
        }
        
        int left = 0,right = 0;

        if(root->left)
         left = rec(root->left);
        if(root->right)
         right = rec(root->right);
        int curr = root->val + left +right;
        root->val = curr;

        return root->val;
    }

    long long ans(TreeNode *root,long long tot) {
       if(root == NULL) return 0;

       long long left = max(((tot-(long long)root->val) * (long long)root->val),ans(root->left,tot));
       long long right = max(((tot-(long long)root->val) * (long long)root->val),ans(root->right,tot));

       return max(left,right);


    }

    int maxProduct(TreeNode* root) {
                if(root==NULL) return 0;
                rec(root);
                return ans(root,root->val)%MOD;
    }
};