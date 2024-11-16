int ans = -1;
int findCeil(Node* root, int input) {
    
    if(root==NULL) return ans;
        
        if(root->data == input) {
            ans = input;
            return ans;
        }
        if(ans!=input) {
            if(root->data > input) {
            ans = root->data;
            findCeil(root->left,input);
        }
        
        if(root->data < input) {
            findCeil(root->right,input);
        }
        }
        
        
        return ans;
}