// long long rec(vector<vector<int>>& questions,int i,vector<long long> &dp) {
    //     if(i>=questions.size()) {
    //         return 0;
    //     }

    //     if(dp[i]!=-1) {
    //         return dp[i];
    //     }

    //     long long include = questions[i][0] + rec(questions,i+questions[i][1]+1,dp);
    //     long long exclude = 0 + rec(questions,i+1,dp);

    //     dp[i] = max(include,exclude);
    //     return dp[i]; 
    // }

    // long long bottomup(vector<vector<int>>& questions) {
    //     int n=questions.size();
    //     int add=0;
    //     for(int i=0;i<n;i++) {
    //         add= max(add,questions[i][1]);
    //     }
    //     vector<long long> dp(n+add+2,0);
    //     for(int i=n-1;i>=0;i--) {
    //         long long include = questions[i][0] + dp[i+questions[i][1]+1];
    //         long long exclude = 0 + dp[i+1];
    //          dp[i] = max(include,exclude);
    //     }

    //     return dp[0];

    // }

  

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        int add=0;
        for(int i=0;i<n;i++) {
            add= max(add,questions[i][1]);
        }
        long long prev=0;
        long long curr = 0;
        for(int i=n-1;i>=0;i--) {
            long long include = questions[i][0] + dp[i+questions[i][1]+1];
            long long exclude = 0 + dp[i+1];
             dp[i] = max(include,exclude);
        }

        return dp[0];
    }