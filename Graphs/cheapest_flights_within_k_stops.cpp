int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int,list<pair<int,int>>> adj;

    for(auto flight:flights) {
        adj[flight[0]].push_back({flight[1],flight[2]});
    }

    vector<int> dist(n,INT_MAX);
    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{src,0}});
    dist[src] = 0;

    while(!pq.empty()) {
        auto front = pq.front();
        int distance = front.first;
        int node = front.second.first;
        int c_k = front.second.second;
        cout << distance << " " << node << " " << c_k << endl;
        pq.pop();
        if(c_k>k) continue;
        
        for(auto nbr : adj[node]) {
            
                int nbrnode = nbr.first;
                int wt = nbr.second;
                if(nbrnode == dst && c_k <=k ) {
                       dist[dst] = min(dist[dst],distance+wt);
                }

                else if(distance+wt<dist[nbrnode]) {
                    dist[nbrnode] = distance+wt;
                    pq.push({distance+wt,{nbrnode,c_k+1}});
                }
        }
    }

    if(dist[dst]==INT_MAX) return -1;

    return dist[dst];
}