// Function to return max value that can be put in knapsack of capacity.
    
    
    // int sack(int capacity, vector<int> &val, vector<int> &wt,int i) {
    //     if(capacity==0 || i>=wt.size()) {
    //         return 0;
    //     }
        
    //         int include=INT_MIN;
    //         if(capacity-wt[i]>=0) {
    //             include = val[i]+sack(capacity-wt[i],val,wt,i+1);
    //         }
            
    //         int exclude = 0 + sack(capacity,val,wt,i+1);
            
    //         return max(include,exclude);
            
    // }
    
    
    // int topdown(int capacity, vector<int> &val, vector<int> &wt,int i,vector<vector<int>> &dp) {
    //      if(capacity==0 || i>=wt.size()) {
    //         return 0;
    //     }
        
    //     if(dp[capacity][i]!=-1) {
    //         return dp[capacity][i];
    //     }
        
    //         int include=INT_MIN;
    //         if(capacity-wt[i]>=0) {
    //             include = val[i]+topdown(capacity-wt[i],val,wt,i+1,dp);
    //         }
            
    //         int exclude = 0 + topdown(capacity,val,wt,i+1,dp);
            
    //         dp[capacity][i] = max(include,exclude);
    //         return dp[capacity][i];
    // }
    
    
    
    int bottomup(int capacity, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(capacity+1,vector<int>(wt.size()+1,0));
        
        
        for(int i=1;i<=capacity;i++) {
            for(int j=wt.size()-1;j>=0;j--) {
                
                
            int include=INT_MIN;
            if(i-wt[j]>=0) {
                include = val[j]+dp[i-wt[j]][j+1];
            }
            
            int exclude = 0 + dp[i][j+1];
            
            dp[i][j] = max(include,exclude);
                
            }
        }
        
        return dp[capacity][0];
    }
    
    
    
    
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // vector<vector<int>> dp(capacity+1,vector<int>(wt.size(),-1));
        // return sack(capacity,val,wt,0);
        // return topdown(capacity,val,wt,0,dp);
        return bottomup(capacity,val,wt);
    }