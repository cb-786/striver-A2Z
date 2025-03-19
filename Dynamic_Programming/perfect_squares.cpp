// int rec(int n,int &i,vector<int> &dp) {
    //     if(n<=0) {
    //         if(n==0) {
    //             return 0;
    //         }

    //         else {
    //             return INT_MAX;
    //         }


    //     }

    //     if(dp[n]!=-1) {
    //         return dp[n];
    //     }

    //    int mini = INT_MAX;
    //     for(int j=1;j<=i;j++) {
    //         if(j*j<=n) {
    //             int recans = rec(n-(j*j),i,dp);
    //             if(recans!=INT_MAX) {
    //                 int answer = 1 + recans;
    //                 mini = min(mini,answer);
    //             }
                
    //         }
    //     }

    //     dp[n] = mini;
    //     return dp[n];
    // }


    int bottomup(int n) {
        vector<int> dp(n+1,-1);
         int i=0;
        while(i*i<=n) {
            if((i+1)*(i+1) > n) {
                break;
            }
            i++;
        }

        dp[0] = 0;

        for(int k=1;k<=n;k++) {
             int mini = INT_MAX;
                for(int j=1;j<=i;j++) {
                    if(j*j<=k) {
                        if(k-(j*j)>=0) {
                            int answer = 1 + dp[k-(j*j)];
                            mini = min(mini,answer);
                        }
                    }
                }

                dp[k] = mini;
        }

        return dp[n];
    }




    int numSquares(int n) {
        
        
       return bottomup(n);
        
    }