int rec(int &m,int &n,int i,int j,int count,vector<vector<int>> &dp) {

    if(i>=m || j>=n) {
        return count;
    }

    if(i==m-1 && j==n-1) {
        count++;
        return count;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }


  int right=  rec(m,n,i,j+1,count,dp);
  int down=  rec(m,n,i+1,j,count,dp);

    dp[i][j] = (right+down);
    return dp[i][j];
}



int uniquePaths(int m, int n) {

   vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
   return rec(m,n,0,0,0,dp);

}