int climbstairs(int n,vector<int> &dp) {

         if(n==1) return 1;

        if(n==0) {
        
            return 0;
        }

         if(dp[n]!=-1) {
            return dp[n];
         }

        dp[n] =  climbstairs(n-1,dp) + climbstairs(n-2,dp);
    return dp[n];
         
    }



    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
         climbstairs(n,dp);
       dp[0] = 0;
        dp[1] = 1;
        return dp[n] + dp[n-1];

    }