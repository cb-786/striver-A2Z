vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        stack<TreeNode*> st;
        vector<int> ans;
        unordered_map<TreeNode *,bool> vis;
        st.push(root);

        while(!st.empty()) {
            auto top = st.top();
            while(top->left && !vis[top->left]) {
                vis[top->left] = 1;
                st.push(top->left);
                top = top->left;
            }

            if(top->right && !vis[top->right]) {
                vis[top->right] = 1;
                st.push(top->right);
                continue;
            }

            ans.push_back(top->val);
            st.pop();
        }

        return ans;
    }