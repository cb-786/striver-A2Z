bool ans = true;
   void inorder(TreeNode *root,vector<int> &arr) {
    if(root==NULL) return;
    
    if(root->left)
    if(root->left->val >= root->val) ans = false;



    if(root->right)
    if(root->right->val<=root->val) ans = false;


    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);

   }


    bool isValidBST(TreeNode* root) {

       vector<int> arr;
       inorder(root,arr);
       if(ans==false) return false;

       vector<int> arr1;
       arr1=arr;
       sort(arr1.begin(),arr1.end());

       for(int i=0;i<arr1.size()-1;i++) {
        if(arr1[i]==arr1[i+1]) {
            return false;
        }
       }



       if(arr1!=arr) return false;

       return true;

    }