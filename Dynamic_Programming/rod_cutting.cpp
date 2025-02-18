 // int rec(vector<int> &price,int n,int i) {
    //     if(i>=price.size() || n<=0) {
    //         return 0;
    //     }
        
        
    //     int exclude = rec(price,n,i+1);
    //     int include =0;
    //     if(n>=(i+1))
    //      include =  price[i] +  rec(price,n-(i+1),i);
        
    //     return max(include,exclude);
    // }
    
  
    int bottomup(vector<int>& price) {
        int n=price.size();
        vector<vector<int>> dp(price.size()+1,vector<int>(n+1,0));
        
        for(int i_index=price.size()-1;i_index>=0;i_index--) {
            for(int c_index = 0;c_index<=n;c_index++) {
                  int exclude = 0 + dp[i_index+1][c_index];
                  int include = 0;
                  if (c_index >= i_index+1) {  
                      include = price[i_index] + dp[i_index][c_index - (i_index+1)];
                  }
                  dp[i_index][c_index] = max(include,exclude);
            }
            
            
        }
        
        
        return dp[0][n];
        
   }




  int cutRod(vector<int> &price) {
      return bottomup(price);
  }