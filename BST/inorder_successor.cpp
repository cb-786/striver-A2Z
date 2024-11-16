Node *ans=NULL;
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(root==NULL) return ans;
        
        if(root->data > x->data) {
            ans = root;
            inOrderSuccessor(root->left,x);
        }
        
        if(root->data <= x->data) {
            inOrderSuccessor(root->right,x);
        }
        
        return ans;
        
        
    }