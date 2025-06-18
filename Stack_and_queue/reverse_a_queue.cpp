void rec(queue<int> &q) {
       
       
    if(q.empty()) return ;
    
    int tmp = q.front();
    q.pop();
    rec(q);
    q.push(tmp);
}




 queue<int> reverseQueue(queue<int> &q) {
    rec(q);
    return q;
 }