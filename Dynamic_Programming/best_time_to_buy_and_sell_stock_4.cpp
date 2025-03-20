//  int rec(vector<int> &prices,int buy,int i,int num,vector<vector<vector<int>>> &dp) {
    //     if(num==0 || i>=prices.size()) {
    //         return 0;
    //     }
        

    //     if(dp[buy][i][num]!=-1) {
    //         return dp[buy][i][num];
    //     }

    //     if(buy==0) {
    //         int dobuy = -prices[i] + rec(prices,1,i+1,num,dp);

    //         int skipbuy = rec(prices,0,i+1,num,dp);

    //         dp[buy][i][num] = max(dobuy,skipbuy);
    //         return dp[buy][i][num];
    //     }

    //     else {
    //         int dosell = prices[i] + rec(prices,0,i+1,num-1,dp);

    //         int skipsell = 0 + rec(prices,1,i+1,num,dp);

    //         dp[buy][i][num] = max(dosell,skipsell);
    //         return dp[buy][i][num];
    //     }


    // }

      

    int maxProfit(int k, vector<int>& prices) {
        //  int n=prices.size();
        
        // vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(k+1,-1)));

        // return rec(prices,0,0,k,dp);

        int n = prices.size();
    
   
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
    vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));


   
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int num = 0; num < k; num++) {
                if (buy == 0) {
                    int doBuy = -prices[i] + after[1][num];  
                    int skipBuy = after[0][num];  
                    cur[buy][num] = max(doBuy, skipBuy);
                } else {
                    int doSell = prices[i] + after[0][num+1]; 
                    int skipSell = after[1][num];  
                    cur[buy][num] = max(doSell, skipSell);
                }
            }
        }
        after=cur;
    }

    return after[0][0];
    }
};