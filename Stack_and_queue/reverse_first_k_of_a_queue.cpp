queue<int> reverseFirstK(queue<int> q, int k) {
    if(k>q.size()) {
        return q;
    }
    queue<int> ans;
    stack<int> s;
    while(k!=0) {
        s.push(q.front());
        q.pop();
        k--;
    }
    
    while(!s.empty()) {
        ans.push(s.top());
        s.pop();
    }
    
    while(!q.empty()) {
        ans.push(q.front());
        q.pop();
    }
    
    return ans;
    
    
}