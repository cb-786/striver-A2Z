int n = -1;
    int rec(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp) {
        int m = triangle.size();
        if(i<m)
         n = triangle[i].size();
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        int left = triangle[i][j] + rec(triangle,i+1,j,dp);
        int right = triangle[i][j] + rec(triangle,i+1,j+1,dp);

        dp[i][j] = min(left,right);
        return dp[i][j];
    }




    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
        return rec(triangle,0,0,dp);
    }