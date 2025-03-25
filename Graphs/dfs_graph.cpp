void rec(vector<vector<int>>& adj,unordered_map<int,bool> &vis,vector<int> &ans,int src) {
    ans.push_back(src);
    vis[src] = 1;
    
    for(auto nbr : adj[src]) {
        if(!vis[nbr]) {
            rec(adj,vis,ans,nbr);
        }
    }
}






vector<int> dfsOfGraph(vector<vector<int>>& adj) {
  unordered_map<int,bool> vis;
  vector<int> ans;
  
  rec(adj,vis,ans,0);
  return ans;
  
}