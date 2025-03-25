bool cyclic(vector<vector<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int, int>& parent, int src) {
    vis[src] = 1;
     
     for(auto nbr : adj[src]) {
         if(nbr == parent[src]) {
             continue;
         }
         
         if(!vis[nbr]) {
             parent[nbr] = src;
             bool ans = cyclic(adj,vis,parent,nbr);
             if(ans) return ans;
         }
         
         else {
             return true;
         }
     }
     
     return false;
}

bool isCycle(vector<vector<int>>& adj) {
 unordered_map<int, bool> vis;
 unordered_map<int, int> parent;
 
 for (int i = 0; i < adj.size(); i++) {
     if (!vis[i]) {  
         parent[i] = -1;
         if (cyclic(adj, vis, parent, i)) {
             return true;
         }
     }
 }
 return false;
}