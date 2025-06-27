string removeKdigits(string nums, int k) {
    stack<int> st;
    for(int i=0;i<nums.size();i++) {
        while(!st.empty() && st.top()>nums[i] && k>0) {
            st.pop();
            k--;
        }

        st.push(nums[i]);
    }
    while(!st.empty() && k!=0) {
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
int i = 0;
while (i < ans.size() && ans[i] == '0') i++;

ans = ans.substr(i);
return ans.empty() ? "0" : ans;
   
}