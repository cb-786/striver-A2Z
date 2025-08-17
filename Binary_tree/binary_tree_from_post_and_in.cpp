TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;

        for(int i =0;i<inorder.size();i++) {
            map[inorder[i]] = i;
        }

        return rec(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,map);
    }

    TreeNode* rec(vector<int> &inorder,int instart,int inend,vector<int> &postorder,int poststart,int postend,unordered_map<int,int> &map) {

                if(instart > inend || poststart > postend) return NULL;


                TreeNode * root = new TreeNode(postorder[postend]);

                int rin = map[postorder[postend]];
                int numsl = rin - instart;

                root->left = rec(inorder,instart,rin-1,postorder,poststart,poststart+numsl-1,map);

                root->right = rec(inorder,rin+1,inend,postorder,numsl+poststart,postend-1,map);

                return root;
    }