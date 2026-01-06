int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> bfs;
        bfs.push(root);
        bfs.push(NULL);
        int sum = root->val;
        int pans = INT_MIN;
        int level = 1;
        int ans = 0;
        while(!bfs.empty()) {
            TreeNode * top = bfs.front();
            bfs.pop();
            if(top == NULL) {
                
                if(sum > pans) {
                    pans = sum;
                    ans = level;
                }
                sum=0;
                if(bfs.empty()) {
                    break;
                }
                bfs.push(NULL);
                level++;
                
                continue;
            }

            else {
                sum+=top->val;
            }

            if(top->left) bfs.push(top->left);
            if(top->right) bfs.push(top->right);
        }
        return ans;
    }