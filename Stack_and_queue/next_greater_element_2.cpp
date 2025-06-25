vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans;
    stack<int> st;
    

    int f=0;
    for(int i=nums.size()-1;i>=0;i--) {
        while(!st.empty() && st.top()<=nums[i]) {
            st.pop();
        }

        if(st.empty()) {
            for(int j=0;j<i;j++) {
                if(nums[j]>nums[i]) {
                    ans.push_back(nums[j]);
                    f=1;
                    break;
                }
            }
        }

        else {
            ans.push_back(st.top());
            f=1;
        }

        if(f==0) ans.push_back(-1);
        f=0;
        st.push(nums[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;


}