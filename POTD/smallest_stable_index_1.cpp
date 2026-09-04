int firstStableIndex(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int e=INT_MAX;
        int s=INT_MIN;
        vector<int> suffmin;
        for(int i=nums.size()-1;i>=0;i--) {
            e=min(e,nums[i]);
            suffmin.push_back(e);
        }
        reverse(suffmin.begin(),suffmin.end());
        for(int i=0;i<nums.size();i++) {
            s=max(s,nums[i]);
            if(s-suffmin[i] <= k) {
                ans=min(ans,i);
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
        
    }