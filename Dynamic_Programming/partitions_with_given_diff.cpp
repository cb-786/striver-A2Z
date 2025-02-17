int rec(vector<int> &arr,int &d,int sum1,int &sum,int i,vector<vector<int>> &dp) {
    int sum2 = sum-sum1;
    if(i>arr.size()) return 0;
    
    if(i==arr.size()) {
        if(sum1-sum2==d) {
            return 1;
        }
        
        return 0;
        
        
    }
    
    if(dp[sum1][i]!=-1) {
        return dp[sum1][i];
    }
    
    int include=0,exclude=0;
     include += rec(arr,d,sum1+arr[i],sum,i+1,dp);
     exclude += rec(arr,d,sum1,sum,i+1,dp);
    
    dp[sum1][i] = (include+exclude);
    return dp[sum1][i];
}





 int countPartitions(vector<int>& arr, int d) {
     int sum=0;
     for(int i=0;i<arr.size();i++) {
         sum+=arr[i];
     }
     vector<vector<int>> dp(sum+1,vector<int>(arr.size(),-1));
     return rec(arr,d,0,sum,0,dp);
 }