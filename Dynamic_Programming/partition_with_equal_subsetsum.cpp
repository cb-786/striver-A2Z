// bool topdown(vector<int>& nums, int i, int sum, vector<vector<int>> &dp) {
//     if (sum == 0) {
//         return true;
//     }
//     if (i >= nums.size() || sum < 0) {
//         return false;
//     }
//     if (dp[i][sum] != -1) {
//         return dp[i][sum];
//     }
//     bool include = topdown(nums, i + 1, sum - nums[i], dp);
//     bool exclude = topdown(nums, i + 1, sum, dp);
//     dp[i][sum] = (include || exclude);
//     return dp[i][sum];
// }


bool bottomup(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
        return false;
    }
    int targetSum = sum / 2;
    vector<vector<bool>> dp(nums.size()+1, vector<bool>(targetSum+1,0));
    for (int i = 0; i <= nums.size(); i++) {
        dp[i][0] = 1;
    }

    for(int i=nums.size()-1;i>=0;i--) {
        for(int j=0;j<=targetSum;j++) {
             bool include = 0;
            if(j>=nums[i]) {
                include = dp[i+1][j-nums[i]];
            }
            
                
                bool exclude = dp[i+1][j];
                dp[i][j] = (include || exclude);
        }
    }

    return dp[0][targetSum];

}

bool canPartition(vector<int>& nums) {
    // int sum = accumulate(nums.begin(), nums.end(), 0);
    // if (sum % 2 != 0) {
    //     return false;
    // }
    // int targetSum = sum / 2;
    // vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1, -1));
    return bottomup(nums);
}