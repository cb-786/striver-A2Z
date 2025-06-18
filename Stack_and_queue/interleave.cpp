queue<int> rearrangeQueue(queue<int> q) {
    queue<int> q2;
    int n = q.size();
    int k = n/2;
    while(k!=0) {
        q2.push(q.front());
        q.pop();
        k--;
    }
    
    k=n/2;
    while(k!=0) {
        q.push(q2.front());
        q.push(q.front());
        q.pop();
        q2.pop();
        k--;
    }
    
    return q;
    
 }