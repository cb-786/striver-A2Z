int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(const auto& ele: a ) {
            pq.push(ele);
        }
        
        for(const auto &ele : b) {
            pq.push(ele);
        }
        
        while(k!=1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }