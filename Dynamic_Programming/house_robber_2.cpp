int topdown(vector<int> &nums,int i,int flag,vector<vector<int>> &dp) {
    if(i>=nums.size()) {
        return 0;
    }

    if(i==nums.size()-1) {
        if(flag==1) {
            flag=0;
            return 0;
        }

        else {
            return nums[nums.size()-1];
        }
    }

    if(dp[i][flag]!=-1) {
        return dp[i][flag];
    }

    
    if(i==0) {
        flag=1;
    }

    int include = nums[i] + topdown(nums,i+2,flag,dp);
    if(i==0) {
        flag=0;
    }
    int exclude = 0 + topdown(nums,i+1,flag,dp);

    dp[i][flag] = max(include,exclude);
    return dp[i][flag];

    
}

int rob(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1));
    return topdown(nums,0,0,dp);
}