vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,int> mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            
            auto tmp = q.front();
            q.pop();
            Node *temp = tmp.first;
            int line = tmp.second;
            
            
            mp[line] = temp->data;
            
            if(temp->left) {
                q.push({temp->left,line-1});
            }
            
            if(temp->right) {
                q.push({temp->right,line+1});
            }
        }
        
        for(auto it:mp) {
            ans.push_back(it.second);
        }
        
        return ans;
        
        
    }