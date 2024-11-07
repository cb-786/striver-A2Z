class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {



        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> temp;


        if(root==NULL) {
            return  ans;
        }
        while(!q.empty()) {
            
            if(q.front() == NULL) {

                 ans.push_back(temp);
                 temp.clear();
                 
                 q.pop();
                 if(!q.empty()) q.push(NULL);
                 continue;
            }
            

            temp.push_back(q.front()->val);

            if(q.front()->left !=NULL)
            q.push(q.front()->left);

            if(q.front()->right!=NULL) {
                q.push(q.front()->right);
            }

            q.pop();


        }

        return ans;

    }
};