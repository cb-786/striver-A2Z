vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int,bool> vis;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()) {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        
        
        for(auto nbr:adj[frontnode]) {
            if(!vis[nbr]) {
                q.push(nbr);
                vis[nbr] =1;
            }
        }
    }
    return ans;
    
}