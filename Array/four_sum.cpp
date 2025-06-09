vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    
    if(nums.size()<4) {
        return ans;
    }
    for(int j=0;j<nums.size()-3;j++) {
            

        if(j>0 && nums[j]==nums[j-1]) continue;
        int tar1 = target-nums[j];



    for(int i=j+1;i<nums.size()-2;i++) {
    if (i > j + 1 && nums[i] == nums[i - 1]) continue;
    long long tar = (long long)tar1-(long long)nums[i];
    int l = i+1;
    int r = nums.size()-1;
    

    while(l<r) {
            if(nums[l]+nums[r]==tar) {
        ans.push_back({nums[j],nums[i],nums[l],nums[r]});

        l++;
                    while(l<r and nums[l] == nums[l-1]) {
                        l++;
                    }

    }

    else if(nums[l] + nums[r] < tar) {
        l++;
    }

    else {
        r--;
    }
}
    
    
}
    }
    return ans;
}