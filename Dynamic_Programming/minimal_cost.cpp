int rec(int k,vector<int> &arr,int i,vector<int>& dp) {
        
        dp[0] = 0;
        
        for(i=1;i<arr.size();i++) {
            int r = INT_MAX;
        
        for(int j=1;j<=k;j++) {
            
            if(i-j>=0) {
                int mm = dp[i-j] + abs(arr[i]-arr[i-j]);
                r =  min(mm,r);
            }
           
        }
        dp[i] = r;
        }
        
        
        return dp[arr.size()-1];
        
        
    }
  
  
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size(),-1);
        return rec(k,arr,arr.size()-1,dp);
    }