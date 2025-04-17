int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(auto edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }
    for(int i=0;i<n;i++) {
        dist[i][i] = 0;
    }

    for(int h=0;h<n;h++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][h] + dist[h][j]);
            }
        }
    }
     int cityWithFewestReachable = -1;
    int fewestReachableCount = n;

    
    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }  // Skip self
            if (dist[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }
        // Update the city with the fewest reachable cities
        if (reachableCount <= fewestReachableCount) {
            fewestReachableCount = reachableCount;
            cityWithFewestReachable = i;
        }
    }
    return cityWithFewestReachable;
}