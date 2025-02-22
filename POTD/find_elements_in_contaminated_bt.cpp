class FindElements {
    public:
        TreeNode *root;
        void recover(TreeNode *root) {
    
            if(root==NULL) {
                return ;
            }
    
    
    
             if(root->right!=NULL) {
                
                (root->right)->val = (root->val) *2 + 2;
            }
    
            if(root->left!=NULL) {
                (root->left)->val = (root->val) *2 + 1;
            }
    
            recover(root->left);
            recover(root->right);
    
            return ;
        }
    
    
    
    
        FindElements(TreeNode* root) {
           
            this->root = root;
            root->val=0;
            recover(root);
            
            
        }
    
    
        bool f(int &target,TreeNode *root) {
                if(root==NULL) return false;
    
                        if(root->val==target) {
                            return true;
                        }
    
                        bool left = f(target,root->left);
                        bool right = f(target,root->right);
    
                        return (left||right);
                    }
                    
                    bool find(int target) {
                          
                        return f(target,root);
                    }
    };