 // int topdown(int n,int k,vector<int> &dp) {
    //      if(n==1) {
    //         return k;
    //     }
        
    //     if(n==2) {
    //         return k+k*(k-1);
    //     }
        
    //     if(dp[n]!=-1) {
    //         return dp[n];
    //     }
        
    //     dp[n] = (k-1)*(countWays(n-2,k) + countWays(n-1,k));
    //     return dp[n];
    // }
    
    
    // int bottomup(int n,int k) {
    //     vector<int> dp(n+1,-1);
    //     dp[1] = k;
    //     dp[2] = (k+k*(k-1));
        
    //     for(int i=3;i<=n;i++) {
    //         dp[i] = (k-1)*(dp[i-2] + dp[i-1]);
    //     }
        
    //     return dp[n];
    // }
  
  
    int bottomupso(int n,int k) {
        if(n==1) {
            return k;
        }
        
        if(n==2) {
            return (k+k*(k-1));
        }
        int prev1 = k;
        int prev2 = (k+k*(k-1));
        int curr = 0;
        for(int i=3;i<=n;i++) {
            curr = (k-1)*(prev1 + prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        
        return curr;
    }
  
  
  
    int countWays(int n, int k) {
    //     vector<int> dp(n+1,-1);
    //   return topdown(n,k,dp);
       
       return bottomupso(n,k);
    }