int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int , vector<int>,greater<int>> pq;
    for(const auto& ele: arr) {
        pq.push(ele);
    }
    
    while(k!=1) {
        pq.pop();
        k--;
    }
    
    return pq.top();
    
}