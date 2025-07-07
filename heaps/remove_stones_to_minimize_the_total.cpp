int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(piles.begin(),piles.end());

    while(k!=0) {
        int top = pq.top();
        pq.pop();
        int rem = top>>1;
        pq.push(top-rem);
        k--;
    }
    int ans=0;
    while(!pq.empty()) {
        ans+=pq.top();
        pq.pop();
    }
    return ans;
}