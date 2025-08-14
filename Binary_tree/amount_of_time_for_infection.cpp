TreeNode * rec(TreeNode *root,int start) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == start) {
            return root;
        }

        TreeNode *left = rec(root->left,start);
        TreeNode *right = rec(root->right,start);

        if(left != NULL) return left;

        return right;
    }


    int amountOfTime(TreeNode* root, int start) {
        TreeNode *s = rec(root,start);

        unordered_map<TreeNode *,TreeNode *> par;
        unordered_map<TreeNode *,bool> vis;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
                par[curr->left] = curr;
            }

            if(curr->right) {
                q.push(curr->right);
                par[curr->right] = curr;
            }
        }


        int time = -1;
        q.push(s);
        q.push(NULL);
        while(!q.empty()) {
            time++;

            while(q.front() != NULL) {
                auto curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                }

                if(curr->right && !vis[curr->right]) q.push(curr->right);

                if(par[curr]!=NULL && !vis[par[curr]]) q.push(par[curr]);

                vis[curr]=1;
            }

                q.pop();
                if(!q.empty()) q.push(NULL);
            
            
        }

        return time;
        
    }