void leftSideView(Node* root,vector<int> &ans) {
        if(root==NULL) return ;
        
        if(root->left || root->right) ans.push_back(root->data);
        
        if(root->left) leftSideView(root->left,ans);
        else leftSideView(root->right,ans);
        
    }
    
    void rightSideView(Node* root,vector<int> &ans) {
       if(root==NULL) return ;
        
        if(root->left || root->right) ans.push_back(root->data);
        
        if(root->right) rightSideView(root->right,ans);
       else rightSideView(root->left,ans);
        
    }
    
    Node* bottomView(Node *root,vector<int> &ans) {
        // code here
        if(root==NULL) return NULL;
        
        Node *ll = bottomView(root->left,ans);
        Node *rr = bottomView(root->right,ans);
        
        if(ll==NULL && rr==NULL) ans.push_back(root->data);
        
        return root;
    }
    
    vector<int> boundaryTraversal(Node *root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        
        // 1. Add the main root first (only if it's not a leaf itself)
        if(root->left || root->right) ans.push_back(root->data);
        
        // 2. Start left boundary strictly on the left child
        vector<int> lv;
        leftSideView(root->left, lv);
        
        // 3. Collect all leaves
        vector<int> bv;
        bottomView(root, bv);
        
        // 4. Start right boundary strictly on the right child
        vector<int> rv;
        rightSideView(root->right, rv);
        
        // Assemble the final array
        for(const auto &ele : lv) ans.push_back(ele);
        for(const auto &ele : bv) ans.push_back(ele);
        for(int i = rv.size() - 1; i >= 0; i--) ans.push_back(rv[i]);
        
        // Removed ans.pop_back() because we prevented duplicates cleanly!
        return ans;
        
    }