void insert(stack<int> &s,int &x) {
    if (s.empty() || s.top() <= x) {
    s.push(x);
    return;
}
    
    int tmp=0;
    if(!s.empty()) {
        tmp = s.top();
        s.pop();
    }
    insert(s,x);
    s.push(tmp);
}


void SortedStack ::sort() {
    if(s.empty()) return;
    int tmp = 0;
    if(!s.empty()) {
    tmp = s.top();
    s.pop();
    }
    
    sort();
    insert(s,tmp);
    
    
    
}