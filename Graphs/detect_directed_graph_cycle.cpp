vector<int> topoSort(int V, vector<vector<int>>& edges,vector<int> &vis) {
    vector<int> indeg(V,0);
    vector<int> ans;
            vector<vector<int>> adj(V);
    for (auto row : edges) {
        adj[row[0]].push_back(row[1]);
        }
    for(auto row:edges) {
        indeg[row[1]]++;
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




bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V,0);
    topoSort(V,edges,vis);
    for(auto k:vis) {
        if(k==0) return true;
    }
    return false;
    
}