int rec(vector<vector<int>> &arr,int n,int i,vector<vector<int>> &dp) {
    if(i>=3 || n>=arr.size()) {
        return 0;
    }
    
    int include0=INT_MIN,include1=INT_MIN,include2=INT_MIN;
    
    
    
    if(i==-1) {
         include0 = arr[n][0] + rec(arr,n+1,0,dp);
         include1 = arr[n][1] + rec(arr,n+1,1,dp);
         include2 = arr[n][2] + rec(arr,n+1,2,dp);
    }
    
    
    else {
        
        if(dp[n][i]!=-1)
        return dp[n][i];
        
        
         if(i==0) {
        include1 = arr[n][1] + rec(arr,n+1,1,dp);
         include2 = arr[n][2] + rec(arr,n+1,2,dp);
    }
    if(i==1) {
        include0 = arr[n][0] + rec(arr,n+1,0,dp);
        include2 = arr[n][2] + rec(arr,n+1,2,dp);
    }
    
    if(i==2) {
        include0 = arr[n][0] + rec(arr,n+1,0,dp);
        include1 = arr[n][1] + rec(arr,n+1,1,dp);
    }
    
    }
    
    if(i!=-1) {
        dp[n][i]= max(include0,max(include1,include2));
    }
    
     return max(include0,max(include1,include2));
   
    
}

 int maximumPoints(vector<vector<int>>& arr) {
     vector<vector<int>> dp(arr.size()+1,vector<int>(4,-1));
     return rec(arr,0,-1,dp);
 }