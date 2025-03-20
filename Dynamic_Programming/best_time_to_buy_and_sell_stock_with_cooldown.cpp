// int rec(vector<int> &prices,int i,int buy,vector<vector<int>> &dp) {
    //     if(i>=prices.size()) {
    //         return 0;
    //     }

    //     if(dp[i][buy]!=-1) {
    //         return dp[i][buy];
    //     }

    //     if(buy==0) {
    //         int dobuy = -prices[i] + rec(prices,i+1,1,dp);

    //         int skipbuy = rec(prices,i+1,0,dp);

    //         dp[i][buy] = max(dobuy,skipbuy);
    //         return dp[i][buy];
    //     }

    //     else {
    //         int dosell = prices[i] + rec(prices,i+2,0,dp);

    //         int skipsell = rec(prices,i+1,1,dp);

    //         dp[i][buy] = max(dosell,skipsell);
    //         return dp[i][buy];
    //     }
    // }


    int bottomup(vector<int> &prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));

        for(int ind=prices.size()-1;ind>=0;ind--) {
                 for(int buy=0;buy<=1;buy++) {
                    if(buy==0) {
            int dobuy = -prices[ind] + dp[ind+1][1];

            int skipbuy = dp[ind+1][0];

            dp[ind][buy] = max(dobuy,skipbuy);
           
        }

        else {
            int dosell = prices[ind] + dp[ind+2][0];

            int skipsell = dp[ind+1][1];

            dp[ind][buy] = max(dosell,skipsell);
            
        }
                 }
        }

       return dp[0][0];
    }




    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return rec(prices,0,0,dp);
        return bottomup(prices);
    }