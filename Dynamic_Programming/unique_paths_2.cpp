int rec(vector<vector<int>>& obstacleGrid,int &m,int &n,int i,int j,int count,vector<vector<int>> &dp) {

    if(i>=m || j>=n || obstacleGrid[i][j]==1) {
        return count;
    }

    if(i==m-1 && j==n-1) {
        count++;
        return count;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }


  int right=  rec(obstacleGrid,m,n,i,j+1,count,dp);
  int down=  rec(obstacleGrid,m,n,i+1,j,count,dp);

    dp[i][j] = (right+down);
    return dp[i][j];
}



int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return rec(obstacleGrid,m,n,0,0,0,dp);

}