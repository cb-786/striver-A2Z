int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = INT_MIN;

    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++) {
        dp[i][0] = ((int)matrix[i][0] - '0') ;
        if(dp[i][0]==1) ans=1;
        
    }

    for(int i=0;i<n;i++) {
        dp[0][i] = ((int)matrix[0][i] - '0');
        if(dp[0][i]==1) ans=1;
       
    }
 

    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            if(matrix[i][j]=='1') {
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                 ans = max(ans,dp[i][j]);
            }
        }
    }

    if(ans==INT_MIN) return 0;

    return ans*ans;
}