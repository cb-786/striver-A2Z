vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V,pow(10,8));
    dist[src] = 0;
    for(int i=0;i<V-1;i++) {
        bool updated = false;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt= edge[2];
            if(dist[u] != pow(10,8) && dist[v] > dist[u] + wt) {
                updated = true;
                dist[v] = dist[u] + wt;
            }
        }
        if(updated == false) {
            break;
        }
    }
    
    
    
     bool updated = false;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt= edge[2];
            if(dist[u] != pow(10,8) && dist[v] > dist[u] + wt) {
                return {-1};
            }
        }
        
        
        
        
        return dist;
    
    
    
    
}