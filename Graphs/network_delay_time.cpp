int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto time:times) {
        adj[time[0]].push_back({time[1],time[2]});
    }
    queue<pair<int,int>> q;
    vector<int> dist(n+1,INT_MAX);
    dist[k] = 0;
    q.push({0,k});
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        int distance = front.first;
        int node = front.second;
        
        for(auto lis : adj[node]) {
            int nbr = lis.first;
            int wt = lis.second;
            if(distance+wt < dist[nbr]) {
                dist[nbr] = distance+wt;
                q.push({distance+wt,nbr});
            }
        }
    }
    int ans = INT_MIN;
    for(int i =1;i<dist.size();i++) {
        if(dist[i]==INT_MAX) return -1;

        ans = max(ans,dist[i]);

    }

    return ans;
    
}
};