void rec(stack<int> &st,int &x) {
    if(st.empty()) {
        st.push(x);
        return ;
    }
    int tmp=0;
    if(!st.empty()) {
        tmp = st.top();
        st.pop();
    }
    rec(st,x);
    st.push(tmp);
    
}



stack<int> insertAtBottom(stack<int> st, int x) {
    rec(st,x);
    return st;
}