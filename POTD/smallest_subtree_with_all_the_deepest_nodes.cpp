class Solution {
public:
    int maxi = 0;

    void rec(TreeNode *root, vector<int> &par, vector<int> &depth) {
        if (root == NULL) return;

        if (root->left) {
            par[root->left->val + 1] = root->val + 1;
            depth[root->left->val + 1] = depth[root->val + 1] + 1;
            maxi = max(maxi, depth[root->left->val + 1]);
            rec(root->left, par, depth);
        }

        if (root->right) {
            par[root->right->val + 1] = root->val + 1;
            depth[root->right->val + 1] = depth[root->val + 1] + 1;
            maxi = max(maxi, depth[root->right->val + 1]);
            rec(root->right, par, depth);
        }
    }

    TreeNode* finde(TreeNode *root, int value) {
        if (root == NULL) return NULL;
        if (root->val == value) return root;

        TreeNode *left = finde(root->left, value);
        if (left) return left;
        return finde(root->right, value);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) return NULL;

        vector<int> par(501, 0);
        vector<int> depth(501, -1);

        depth[root->val + 1] = 0;
        rec(root, par, depth);

        set<int> ans;
        for (int i = 0; i < 501; i++) {
            if (depth[i] == maxi) ans.insert(i);
        }

        while (ans.size() > 1) {
            set<int> next;
            for (int ele : ans) {
                next.insert(par[ele]);
            }
            ans = next;
        }

        int value = *ans.begin() - 1;
        return finde(root, value);
    }
};
