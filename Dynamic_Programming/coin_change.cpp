   
//    int coin(vector<int> &coins,int amount,vector<int> &dp) {
//        if(amount==0) return 0;
         
//          if(dp[amount]!=-1) {
//             return dp[amount];
//          }

//          int mini = INT_MAX;
//         for(int i=0;i<coins.size();i++) {
//             if(amount-coins[i] >=0) {
//                 int rec =  coin(coins,amount-coins[i],dp);
//                 if(rec!=INT_MAX) {
//                  int ans = 1  +  rec;
//                  mini = min(mini,ans);
//                 }
//             }
//         }
        
//         dp[amount]= mini;
//         return dp[amount];
//      }




     int bottomup(vector<int> &coins,int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int j=1;j<=amount;j++) {
            int mini = INT_MAX;
           for(int i=0;i<coins.size();i++) {
               if(j-coins[i] >=0) {
                    int rec =  dp[j-coins[i]];
                    if(rec!=INT_MAX) {
                        int ans = 1  +  rec;
                        mini = min(mini,ans);
                        }
            }
        }
          dp[j]= mini;
         
 
        }
       
        return dp[amount];
     }



    int coinChange(vector<int>& coins, int amount) {
          
        int ans=bottomup(coins,amount);
        if(ans == INT_MAX) {
            return -1;
        }

        else {
            return ans;
        }
    }