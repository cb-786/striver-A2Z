bool rec(vector<int> &arr,int &target,int i,int sum,vector<vector<int>> &dp) {
       
    if(sum==target) {
        return true;
    }
    
    if(i>=arr.size() || sum>target) return false;
    
    
    
    if(dp[i][sum]!=-1) {
        return dp[i][sum];
    }
    
    
    
    bool include = rec(arr,target,i+1,sum+arr[i],dp);
    
    bool exclude = rec(arr,target,i+1,sum,dp);
    
    
  dp[i][sum] =   (include||exclude);
  return dp[i][sum];
    
}




 bool isSubsetSum(vector<int>& arr, int target) {
     vector<int> sub;
     vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
    return rec(arr,target,0,0,dp);
 }