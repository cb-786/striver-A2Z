int minimumMultiplications(vector<int>& arr, int start, int end) {
         
          
         
    vector<int> dist(100000,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()) {
        auto front = pq.top();
        int distance = front.first;
        int node = front.second;
        pq.pop();
        if(dist[node]<distance) continue;
        if(node == end) {
            return distance;
        }
        
        for(auto k : arr) {
            int nbr = node * k %100000;
            if(distance+1<dist[nbr]) {
                dist[nbr] = distance+1;
                pq.push({distance+1,nbr});
            }
        }
        
    }
    
    return -1;
    
    
}