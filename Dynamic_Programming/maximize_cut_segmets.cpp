// Function to find the maximum number of cuts.
    
    // int topdowndprec(int n, int x, int y, int z,vector<int>& dp) {
        
    //      if(n<=0) {
    //         if(n==0) {
    //               return 0;
    //         }
          
            
    //         else {
    //             return INT_MIN;
    //         }
            
    //     }
      
    //   if(dp[n-1] != -1) {
    //       return dp[n-1];
    //   }
      
        
    //   int opt1 = 1 + topdowndprec(n-x,x,y,z,dp);
    //   int opt2 = 1 + topdowndprec(n-y,x,y,z,dp);
    //   int opt3 = 1 + topdowndprec(n-z,x,y,z,dp);
        
        
    //     dp[n-1] = max(opt1,max(opt2,opt3));
    //     return dp[n-1];
        
    // }
    
    
    
    int bottomupdp(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1); // Initialize DP array with -1 (unreachable state)
    dp[0] = 0; // Base case: Length 0 has 0 segments

    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1) 
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1) 
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1) 
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return (dp[n] == -1) ? 0 : dp[n]; // If `dp[n]` is -1, return 0
    }
    
    
  
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        return bottomupdp(n,x,y,z);
       
        
       
    }