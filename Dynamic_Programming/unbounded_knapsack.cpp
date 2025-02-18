// int rec(vector<int>& val, vector<int>& wt, int capacity,int i,vector<vector<int>> &dp) {
    //     if(capacity<=0 || i>=wt.size()) {
    //         return 0;
    //     }
        
    //     if(dp[i][capacity]!=-1) {
    //         return dp[i][capacity];
    //     }
        
        
    //     int exclude = 0 + rec(val,wt,capacity,i+1,dp);
    //      int include = 0;
    //         if (capacity >= wt[i]) {  
    //             include = val[i] + rec(val, wt, capacity - wt[i], i,dp);
    //         }
        
    //     dp[i][capacity] = max(include,exclude);
    //     return dp[i][capacity];
        
        
        
    // }
  
  
    int bottomup(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>> dp(wt.size()+1,vector<int>(capacity+1,0));
        
        for(int i_index=wt.size()-1;i_index>=0;i_index--) {
            for(int c_index = 0;c_index<=capacity;c_index++) {
                  int exclude = 0 + dp[i_index+1][c_index];
                  int include = 0;
                  if (c_index >= wt[i_index]) {  
                      include = val[i_index] + dp[i_index][c_index - wt[i_index]];
                  }
                  dp[i_index][c_index] = max(include,exclude);
            }
            
            
        }
        
        
        return dp[0][capacity];
        
   }





  int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
      // vector<vector<int>> dp(wt.size(),vector<int>(capacity+1,-1));
      return bottomup(val,wt,capacity);
  }