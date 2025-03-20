 // int rec(vector<int> &prices,int buy,int i,int num,vector<vector<vector<int>>> &dp) {
    //     if(num==2 || i>=prices.size()) {
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
    //         int dosell = prices[i] + rec(prices,0,i+1,num+1,dp);

    //         int skipsell = 0 + rec(prices,1,i+1,num,dp);

    //         dp[buy][i][num] = max(dosell,skipsell);
    //         return dp[buy][i][num];
    //     }


    // }


//     int bottomup(vector<int>& prices) {
//     int n = prices.size();
    
   
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

   
//     for (int i = n - 1; i >= 0; i--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             for (int num = 0; num < 2; num++) {
//                 if (buy == 0) {
//                     int doBuy = -prices[i] + dp[i+1][1][num];  
//                     int skipBuy = dp[i+1][0][num];  
//                     dp[i][buy][num] = max(doBuy, skipBuy);
//                 } else {
//                     int doSell = prices[i] + dp[i+1][0][num+1]; 
//                     int skipSell = dp[i+1][1][num];  
//                     dp[i][buy][num] = max(doSell, skipSell);
//                 }
//             }
//         }
//     }

//     return dp[0][0][0]; 
// }

int maxProfit(vector<int>& prices) {
    // int n=prices.size();
    
    // vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(3,-1)));

    // return rec(prices,0,0,0,dp);

    // return bottomup(prices);

    int n = prices.size();
    const int k = 2;
    int dp_1_0 = 0;
    int dp_1_1 = -prices[0];
    int dp_2_0 = 0;
    int dp_2_1 = -prices[0];
    for (int i = 1; i < n; i++) {
        int prev = 0;
        for (int t = 1; t <= k; t++) {
            dp_2_0 = max(dp_2_0, dp_2_1 + prices[i]);
            dp_2_1 = max(dp_2_1, dp_1_0 - prices[i]);
            dp_1_0 = max(dp_1_0, dp_1_1 + prices[i]);
            dp_1_1 = max(dp_1_1, -prices[i]);
        }
    }
    return dp_2_0;
}