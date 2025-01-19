void insertsort(stack<int> &st,int element) {
    if(st.empty() || element > st.top()) {
        st.push(element);
        return ;
    }
    int temp = st.top();
    st.pop();
    insertsort(st,element);
    st.push(temp);
    
}



void SortedStack :: sort()
{
    if(s.empty()) return ;
    
    int temp = s.top();
    s.pop();
    sort();
    insertsort(s,temp);
    return ;
    
}