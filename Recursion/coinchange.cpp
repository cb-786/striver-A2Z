void coin(vector<int> &coins,int amount,int i,int curr,int &ans) {
        if(amount==0) {
            ans=min(ans,curr);
            return ;
        }

        if(amount<0) {
            return ;
        }

        for(;i<coins.size();i++) {
            coin(coins,amount-coins[i],i,curr+1,ans);
        }
        
        return ;
     }

    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        coin(coins,amount,0,0,ans);
        if(ans==INT_MAX) return -1;
        return ans;
    }