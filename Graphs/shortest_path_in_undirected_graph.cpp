vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    vector<int> dist(adj.size(),INT_MAX);
    
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int dista = front.first;
        int node = front.second;
        
        for(auto nbr : adj[node]) {
            if(dist[nbr]>dista + 1) {
            dist[nbr] = dista+1;
            pq.push({dista+1,nbr});
        }
        }
        
    }
    for(int i=0;i<dist.size();i++) {
        if(dist[i]==INT_MAX) {
            dist[i] = -1;
        }
    }
    return dist;
    
 }