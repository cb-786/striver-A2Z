class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
        //     vector<int> after(2,0);
        //     vector<int> cur(2,0);
    
        //     for(int ind=prices.size()-1;ind>=0;ind--) {
        //              for(int buy=0;buy<=1;buy++) {
        //                 if(buy==0) {
        //         int dobuy = -prices[ind] + after[1];
    
        //         int skipbuy = after[0];
    
        //         cur[buy] = max(dobuy,skipbuy);
               
        //     }
    
        //     else {
        //         int dosell = (prices[ind] - fee) + after[0];
    
        //         int skipsell = after[1];
    
        //         cur[buy] = max(dosell,skipsell);
                
        //     }
        //              }
        //              after=cur;
        //     }
    
        //    return after[0];
    
    
          int hold = prices[0];
            int cash = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if(prices[i]-fee > hold) {
                    cash += prices[i] - fee -hold;
                    hold = prices[i];
                }
            }
    
            return cash;
    
    
    
    
    
    
    
    
    
        }
    };