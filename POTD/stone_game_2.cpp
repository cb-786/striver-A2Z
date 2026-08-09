int rec(vector<int> &pre,int ind,int m, vector<vector<int>> &dp) {
            if(ind>=(int)pre.size()) return 0;

            // cout << ind << " " << m << endl;
            if(dp[ind + 1][m] != -1) {
            return dp[ind + 1][m];
        }

            int ans=INT_MIN;
           int stones_taken_so_far = (ind == -1) ? 0 : pre[ind];
        int total_remaining = pre.back() - stones_taken_so_far;

        for(int i = 1; i <= 2 * m; i++) {
            if(ind + i < (int)pre.size()) {
                
                int inc = total_remaining - rec(pre, ind + i, max(m, i),dp);
                ans = max(ans, inc);
            }
            else {
                ans = max(ans, total_remaining);
                break; 
            }
        }
         
            return dp[ind + 1][m] = ans;
    }




    int stoneGameII(vector<int>& piles) {
        vector<int> pre;
        int n=piles.size();
        int s=0;
        for(const auto &ele:piles) {
            s+=ele;
            pre.push_back(s);
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return rec(pre,-1,1,dp);
    }