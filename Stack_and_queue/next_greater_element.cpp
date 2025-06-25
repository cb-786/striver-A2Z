vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map;
    vector<int> ans;
    stack<int> st;
    for(int i=0;i<nums2.size();i++) {
        map[nums2[i]] = i;
    }

    for(int i=nums2.size()-1;i>=0;i--) {
        while(!st.empty() && st.top()<nums2[i]) {
            st.pop();
        }

        if(!st.empty()) {
            ans.push_back(st.top());
            st.push(nums2[i]);
        }

        else {
            ans.push_back(-1);
            st.push(nums2[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    vector<int> answer;
    for(int i=0;i<nums1.size();i++) {
        answer.push_back(ans[map[nums1[i]]]);
    }
    return answer;


}