 long long int topdown(int n,vector<long long int> &dp) {
       if(n==0) return 0;
       
       if(n==1) return 1;
       
       if(dp[n]!=-1) {
           return dp[n];
       }
       
       dp[n] = (topdown(n-1,dp) + topdown(n-2,dp))%MOD;
       return dp[n];
       
   }
  
  
  
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return topdown(n,dp);
    }
    
    
    
    long long int bottomUp(int n) {
        vector<long long int> dp(n+1,-1);
        
        if(n==0) return 0;
        dp[0]=0;
        if(n==1) return 1;
        dp[1]=1;
        
        for(int index = 2;index<=n;index++) {
            dp[index] = (dp[index-1] + dp[index-2])%MOD;
        }
        
        return dp[n];
        
    }