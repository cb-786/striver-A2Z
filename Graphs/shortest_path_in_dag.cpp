vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges.size();i++) {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
     vector<int> dist(V,INT_MAX);
   
   dist[0]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   pq.push({0,0});
   
   while(!pq.empty()) {
       auto front = pq.top();
       pq.pop();
       int dista = front.first;
       int node = front.second;
       
       for(auto pnbr : adj[node]) {
           int nbr = pnbr.first;
           int wt = pnbr.second;
           if(dist[nbr]>dista + wt) {
           dist[nbr] = dista+wt;
           pq.push({dista+wt,nbr});
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