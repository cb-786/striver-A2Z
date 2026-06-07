TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int,TreeNode *> map;
    unordered_set<int> childrenVals;
    
    for(const auto &ele : descriptions) {
       int cp = ele[0];
       int cn = ele[1];
       bool il = ele[2];
        if(map[ele[0]]==NULL)
        map[ele[0]] = new TreeNode(ele[0]);
        if(map[ele[1]]==NULL)
        map[ele[1]] = new TreeNode(ele[1]);
        
        
       
        if(il==1) map[ele[0]]->left = map[ele[1]];
        else map[ele[0]]->right = map[ele[1]];

        childrenVals.insert(ele[1]); 
    }
    
    for(const auto &ele : descriptions) {
        if(childrenVals.find(ele[0]) == childrenVals.end()) {
            return map[ele[0]];
        }
    }
   
    
    return nullptr;


    }