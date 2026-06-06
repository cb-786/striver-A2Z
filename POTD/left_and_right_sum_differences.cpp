vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lsum(nums.size(),0);
        vector<int> rsum(nums.size(),0);
        vector<int> ans(nums.size(),0);
        for(int i = 1;i<nums.size();i++) {
            lsum[i] = lsum[i-1] + nums[i-1];
        }
        for(int i = nums.size()-2;i>=0;i--) {
            rsum[i]=rsum[i+1] + nums[i+1];
            ans[i] = abs(rsum[i]-lsum[i]);
        }
        ans[nums.size()-1] = abs(rsum[nums.size()-1]-lsum[nums.size()-1]);
        return ans;
        
    }