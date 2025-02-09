 int MOD = 1e9 +7;
    
  
    int ans(int &n,int &k, int &target,int dice,int i,vector<vector<int>> &dp) {
        
          if(dice==n) {
                 if(i == target) {
                      return 1;
                 } 
                 return 0;
          }

           if(dp[dice][i] != -1) {
            return dp[dice][i];
           }
           
            int ways =0;
           for(int face=1;face<=k;face++) {
                  if(i+face>target) break;
               ways = (ways +   ans(n,k,target,dice+1,i+face,dp)) % MOD;
           }

           dp[dice][i] = ways;
           return dp[dice][i];
    } 



    // int bottomup(int n, int k, int target) {
    //     vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    //     dp[n][target] =1 ;

    //     for(int i=n-1;i>=0;i--) {
    //         for(int j=target;j>=0;j--) {
    //                             int ways =0;
    //                     for(int face=1;face<=k;face++) {
    //                             if(j+face<=target && i+1<=n) {
    //                              ways = (ways +   dp[i+1][j+face]) % MOD;
    //                             }
                           
    //                     }
    //                     dp[i][j] = ways;
    //         }

    //     }

    //     return dp[0][0];
    // }



    int numRollsToTarget(int n, int k, int target) {
      
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return ans(n,k,target,0,0,dp);
    //    return bottomup(n,k,target);
        
    }