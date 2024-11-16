vector<int> ans;
   vector<int> preorderTraversal(TreeNode* root) {

        if(root == NULL) return ans;
        
        stack<TreeNode*> t;
        t.push(root);
        while(!t.empty()) {
           
            ans.push_back(t.top()->val);
           
          
            TreeNode *to = t.top();
            t.pop();
            
                 if(to->right !=NULL)
            t.push(to->right);

            if(to->left!=NULL)
            t.push(to->left);
            
           

            

        }

        return ans; 
    }



    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;

        inorderTraversal(root->left);
        inorderTraversal(root->right);

        preorderTraversal(root->left);
       
        preorderTraversal(root->right);
        
        return ans;


    }