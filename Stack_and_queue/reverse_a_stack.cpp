void rec(stack<int> &st,int &x,int pos) {
    if(pos==1) {
        st.push(x);
        return ;
    }
    int tmp=0;
    if(!st.empty()) {
        tmp = st.top();
        st.pop();
    }
    
    rec(st,x,pos-1);
    st.push(tmp);
    
}




void Reverse(stack<int> &St) {
    int swaps = St.size();
    while(swaps!=0) {
        int x = St.top();
        St.pop();
        rec(St,x,swaps);
        swaps--;
    }
}