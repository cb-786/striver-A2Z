vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<nums.size()-2;i++) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int tar = -nums[i];
        int l = i+1;
        int r = nums.size()-1;

        while(l<r) {
                if(nums[l]+nums[r]==tar) {
            ans.push_back({nums[i],nums[l],nums[r]});

            while(l<r && nums[l] == nums[l+1]) l++;
            while(l<r && nums[r] == nums[r-1]) r--;

            l++;
            r--;

        }

        else if(nums[l] + nums[r] < tar) {
            l++;
        }

        else {
            r--;
        }
    }
        
        
    }
    return ans;
}