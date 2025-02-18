// int rec(vector<int> &nums,int &target,int i,int sum) {
    //               if(i>=nums.size()) {
    //                 if(sum==target) {
    //                     return 1;
    //                 }

    //                 return 0;
    //               }
    //              int include=0,exclude=0;
    //              include += rec(nums,target,i+1,sum+nums[i]);
    //              exclude += rec(nums,target,i+1,sum-nums[i]);

    //             return (include+exclude);

    // }



    // int topdown(vector<int> &nums,int &target,int i,int sum,vector<vector<int>> &dp,int &tsum)  {
    //               if(i==nums.size()) {
    //                 if(sum==target) {
    //                     return 1;
    //                 }

    //                 return 0;
    //               }


    //             if(sum<0) {
    //                 int offset = -sum;
    //                 if(dp[i][tsum+offset]!=-1) {
    //                 return dp[i][tsum+offset];
    //               }
    //             }

    //             else {
    //                 if(dp[i][sum]!=-1) {
    //                 return dp[i][sum];
    //               }
    //             }
                  


    //              int include=0,exclude=0;
    //              include += topdown(nums,target,i+1,sum+nums[i],dp,tsum);
    //              exclude += topdown(nums,target,i+1,sum-nums[i],dp,tsum);
               
    //            if(sum<0) {
    //              int offset = -sum;
    //                    dp[i][tsum+offset] = (include+exclude);
    //                    return dp[i][tsum +offset];
    //            }

    //            else {
    //             dp[i][sum] = (include+exclude);
    //                    return dp[i][sum];
    //            }
                
    // }
    

    
    int rec(vector<int> &arr,int &d,int sum1,int &sum,int i,vector<vector<int>> &dp) {
        int sum2 = sum - sum1;

   if (i == arr.size()) {  // ✅ Fix base case condition
       return (sum1 - sum2 == d) ? 1 : 0;
   }

   if (dp[sum1][i] != -1) {
       return dp[sum1][i];
   }

   int include = 0, exclude = 0;

   // ✅ Fix: Ensure sum1 doesn't exceed sum to prevent out-of-bounds access
   if (sum1 + arr[i] <= sum) {
       include += rec(arr, d, sum1 + arr[i], sum, i + 1, dp);
   }

   exclude += rec(arr, d, sum1, sum, i + 1, dp);

   dp[sum1][i] = include + exclude;
   return dp[sum1][i];
  }

   


   int findTargetSumWays(vector<int>& nums, int target) {
       int sum=0;
       for(int i=0;i<nums.size();i++) {
           sum+=nums[i];
       }

       vector<vector<int>> dp(sum + 1, vector<int>(nums.size() + 1, -1));
       return rec(nums,target,0,sum,0,dp);
   }