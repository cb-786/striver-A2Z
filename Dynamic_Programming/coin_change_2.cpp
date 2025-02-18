// const int MOD = 1e9 +7;
    // int rec(int &amount,vector<int> &coins,int i,int sum) {
    //     if(sum>amount || i>=coins[i]) return 0;

    //     if(sum==amount) return 1;

    //     int ans = 0;
    //     for(;i<coins.size();i++) {
    //             ans+=rec(amount,coins,i,sum+coins[i]);
    //     }

    //     return ans;
    // }

    // int topdown (int &amount,vector<int> &coins,int i,int sum,vector<vector<int>> &dp) {
    //     if(sum>amount || i>=coins.size()) return 0;

    //     if(sum==amount) return 1;

    //     if(dp[i][sum]!=-1) {
    //         return dp[i][sum];
    //     }

    //     int ans = 0;
    //     ans+=topdown(amount,coins,i+1,sum,dp);
    //     ans+=topdown(amount,coins,i,sum+coins[i],dp);

    //     dp[i][sum] = ans;
    //     return dp[i][sum];
    // }
    const long long MOD = 1e9 + 7;  // Large prime number

    long long bottomup(int &amount, vector<int> &coins) 
       {
            int n=coins.size();
            vector<vector<uint64_t>>v(n+1, vector<uint64_t>(amount+1, 0));
            v[0][0]=1;
            for(int i=1; i<=n; i++){
                v[i][0]=1;
                for(int j=1; j<=amount; j++){
                    if(j >= coins[i-1]){
                        v[i][j]= v[i][j-coins[i-1]]+v[i-1][j];
                    }else{
                        v[i][j]=v[i-1][j];
                    }
                }
            }
            return v[n][amount];
        }
    
    
    int change(int amount, vector<int>& coins) {
        return bottomup(amount, coins);  
    }