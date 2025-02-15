//    int rec(vector<vector<int>>& matrix,int i,int j,vector<vector<int>> &dp) {
//         int m = matrix.size();
       
//          int n = matrix[0].size();
//         if(i==m-1) return matrix[i][j];

//         if(j>=n) return 0;

//         if(dp[i][j]!=-1) {
//             return dp[i][j];
//         }
         
//          int left = INT_MAX,right=INT_MAX;
//          if(j-1>=0)
//          left = matrix[i][j] + rec(matrix,i+1,j-1,dp);

//         int down = matrix[i][j] + rec(matrix,i+1,j,dp);
//         if(j+1<m)
//         right = matrix[i][j] + rec(matrix,i+1,j+1,dp);

//         dp[i][j] = min(left,min(down,right));
//         return dp[i][j];
//     }



int bottomup(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),0));
    for(int j=0;j<n;j++) {
        dp[n-1][j] = matrix[n-1][j];
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
           int left = INT_MAX-200,right=INT_MAX-200,down=INT_MAX-200;
     if(j-1>=0)
     left = matrix[i][j] + dp[i+1][j-1];
     if(i+1<n)
     down = matrix[i][j] + dp[i+1][j];
    if(j+1<n)
    right = matrix[i][j] + dp[i+1][j+1];

    dp[i][j] = min(left,min(down,right));
        }
    }

    return *min_element(dp[0].begin(), dp[0].end());;
}







int minFallingPathSum(vector<vector<int>>& matrix) {
    // vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
    int res = INT_MAX;

    res = min(res, bottomup(matrix));

    return res;
}