vector<int> topView(Node *root)
    {
        map<int,map<int,multiset<int>>> nodes;
        
        
        
        
        
        queue<pair<Node*, pair<int, int>>> todo;
        
        
        todo.push({root,{0,0}});
        while(!todo.empty()) {
            auto curr = todo.front();
            todo.pop();
            
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(nodes[x].empty()) {
                nodes[x][y].insert(curr.first->data);
            }
            
            
            if(curr.first->left) {
                todo.push({curr.first->left,{x-1,y+1}});
            }
            
            if(curr.first->right) {
                todo.push({curr.first->right,{x+1,y+1}});
            }
            
            
        }
        
        
        
        vector<int> ans;
        for(auto p:nodes) {
              for(auto q: p.second){
                // Insert node values
                // into the column vector
                ans.insert(ans.end(), q.second.begin(), q.second.end());
            }
                 
                
                
            
        }
        
        return ans;
        
    }