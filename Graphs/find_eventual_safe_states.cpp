vector<int> topoSort(int V, vector<vector<int>>& adj,vector<int> &vis) {
    vector<int> indeg(V,0);
    vector<int> ans;
           
   
    for(auto row:adj) {
        for(auto ele : row) {
        indeg[ele]++;
        }
    }
    
    queue<int> q;
    
    for(int i=0;i<V;i++) {
        if(indeg[i]==0) {
            q.push(i);
            vis[i]=1;
        }
    }
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto nbr:adj[front]) {
            
                indeg[nbr]--;
        
            if(indeg[nbr]==0 && !vis[nbr]) {
                q.push(nbr);
                vis[nbr]=1;
            }
        } 
    }
    return ans;
   
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<vector<int>> revg(graph.size());
    for(int i=0;i<graph.size();i++) {
        for(auto e:graph[i]) {
            revg[e].push_back(i);
        }
    }

    vector<int> vis(revg.size(),0);

    topoSort(revg.size(),revg,vis);

    vector<int> ans;
    for(int i=0;i<vis.size();i++) {
        if(vis[i]) ans.push_back(i);
    }
    return ans;


}