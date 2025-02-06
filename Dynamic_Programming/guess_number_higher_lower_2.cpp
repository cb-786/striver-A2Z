// int rec(int start,int end) {
    //     if(start>=end) {
    //         return 0;
    //     }
    //     int ans = INT_MAX;
    //     for(int i=start;i<end;i++) {
    //         ans = min(ans,i+max(rec(start,i-1),rec(i+1,end)));
    //     }

    //     return ans;
    // }


    //  int topdown(int start,int end,vector<vector<int>> &dp) {
    //     if(start>=end) {
    //         return 0;
    //     }

    //     if(dp[start][end]!=-1) {
    //         return dp[start][end];
    //     }
    //     int ans = INT_MAX;
    //     for(int i=start;i<end;i++) {
    //         ans = min(ans,i+max(topdown(start,i-1,dp),topdown(i+1,end,dp)));
    //     }

    //     dp[start][end] = ans;
    //     return dp[start][end];
    //  }


     int bottomup(int n) {
         vector<vector<int>> dp(n+2,vector<int>(n+1,0));
           

            for(int i=n;i>=1;i--) {
                for(int j=1;j<=n;j++) {

                    if(i>=j) {
                                continue;
                                }


                    int ans = INT_MAX;
        for(int k=i;k<=j;k++) {
            ans = min(ans,k+max(dp[i][k-1],dp[k+1][j]));
        }

        dp[i][j] = ans;
                }
            }

     return dp[1][n];
     }



    int getMoneyAmount(int n) {
        //    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //    return topdown(1,n,dp);
        return bottomup(n);
    }