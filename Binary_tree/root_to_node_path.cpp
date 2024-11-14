vector<vector<int>> ans;
        
        
        void path(Node *root,vector<int> pus) {
            
            if(root==NULL) return ;
            pus.push_back(root->data);
            if(root->left == NULL && root->right == NULL) ans.push_back(pus);
            
            
            
            path(root->left,pus);
            path(root->right,pus);
            
        }
        
        
    vector<vector<int>> Paths(Node* root) {
       vector<int> pus;
       path(root,pus);
       return ans;
        
    }