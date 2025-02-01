// int robbytopdown(vector<int>& nums,int i,vector<int> &dp) {
    //     if(i>=nums.size()) {
    //         return 0;
    //     }

    //     if(dp[i]!=-1) {
    //         return dp[i];
    //     }

    //     int robh = nums[i] + robbytopdown(nums,i+2,dp);
    //     int norobh = 0 + robbytopdown(nums,i+1,dp);

    //     dp[i] = max(robh,norobh);
    //     return dp[i];
    // }

    int robbybottomupso(vector<int> &nums) {
        int n = nums.size();
        //  vector<int> dp(n,-1);
        int prev = nums[n-1];
        int next =0;
        int curr=0;
        for(int i=n-2;i>=0;i--) {
            int tmp=0;
            if(i+2<n) {
                tmp=next;
            }
            int robh = nums[i] + tmp;
            int norobh = 0 + prev;

        curr = max(robh,norobh);

        next=prev;
        prev=curr;

        }

        return prev;
    }



    int rob(vector<int>& nums) {
       
        return robbybottomup(nums);
    }