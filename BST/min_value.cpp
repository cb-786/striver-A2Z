 int minValue(Node* root) {
        if(root==NULL) return NULL;
        int ans = INT_MAX;
        while(root!=NULL) {
            ans = min(root->data,ans);
            root=root->left;
        }
        
        return ans;
    }