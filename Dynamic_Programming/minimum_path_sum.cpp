// int rec(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     if(i>=m || j>=n) {
    //         return INT_MAX - 300;
    //     }

    //      if(dp[i][j]!=-1) {
    //         return dp[i][j];
    //     }

    //     if(i==m-1 && j==n-1) {
    //         return grid[i][j];
    //     }


       

    //     int right =  grid[i][j] + rec(grid,i,j+1,dp);
    //     int down = grid[i][j] + rec(grid,i+1,j,dp);

    //     dp[i][j] = min(right,down);
    //     return dp[i][j];
    // }




    int bottomup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+2,vector<int>(n+2,INT_MAX-300));
        
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
      if (i == m-1 && j == n-1) continue; // Skip already initialized cell

            int right = (j+1 < n) ? grid[i][j]+ dp[i][j+1] : INT_MAX;
            int down = (i+1 < m) ? grid[i][j]+ dp[i+1][j] : INT_MAX;

            dp[i][j] = min(right, down);
            }
        }

        return dp[0][0];

    }




    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return bottomup(grid);
    }