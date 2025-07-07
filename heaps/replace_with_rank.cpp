vector<int> replaceWithRank(vector<int> &arr, int N) {
      
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<arr.size();i++) {
        pq.push({arr[i],i});
    }
    int r=1;
    while(!pq.empty()) {
        auto top = pq.top();
        int ele = top.first;
        int ind = top.second;
        
        pq.pop();
        
        arr[ind] = r;
        
        if(pq.top().first!=ele) 
        r++;
        
    }
    return arr;
}