int maxSum(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans = 0;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >=0 && map[nums[i]]==0) {
                
                ans +=nums[i];
                map[nums[i]]++;
            }
            maxi = max(maxi,nums[i]);
        }

        return (ans == 0 && map[0] == 0) ? maxi : ans;
    }