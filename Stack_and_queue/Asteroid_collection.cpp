vector<int> asteroidCollision(vector<int>& arr) {
    stack<int> st;
    for(int i=0;i<arr.size();i++) {
        if(arr[i]>0) {
            st.push(arr[i]);
        }

        else {
            while(!st.empty() && st.top() > 0 && -arr[i] > st.top()) {
                st.pop();
            }
            
            if(st.empty()) {
                st.push(arr[i]);
                continue;
            }

            else if(-arr[i] == st.top()) {
                st.pop();
                continue;
            }

            else if(-arr[i] < st.top()) {
                continue;
            }

            else {
                st.push(arr[i]);
            }

        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}