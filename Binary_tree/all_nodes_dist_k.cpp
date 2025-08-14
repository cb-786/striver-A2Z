vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> map;
        queue<TreeNode*> q;
        q.push(root);
        map[root] = NULL;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front->left) {
                map[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                map[front->right] = front;
                q.push(front->right);
            }

        }
        vector<int> ans;
        unordered_map<TreeNode *,bool> vis;
        q.push(target);
        q.push(NULL);
        int dist = -1;
        while(!q.empty()) {
            dist++;
            
            
            while(q.front() != NULL) {
                auto curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]) {
                q.push(curr->left);
                }

                if(curr->right && !vis[curr->right]) q.push(curr->right);

                if(map[curr]!=NULL && !vis[map[curr]]) q.push(map[curr]);




                if(dist==k && vis[curr]==0) {
                    ans.push_back(curr->val);
                }
                vis[curr]=1;
            }

                q.pop();
                if(!q.empty()) q.push(NULL);
            
            
        }

        return ans;

        
    }