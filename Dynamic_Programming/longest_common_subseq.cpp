// int lcs(string text1, string text2,int i,int j,vector<vector<int>> &dp) {
    //     if(i>=text1.size() || j>=text2.size()) {
    //         return 0;
    //     }
        

    //     if(dp[i][j]!=-1) {
    //         return dp[i][j];
    //     }

    //     int include = 0;
    //     int ans =0;
        
    //        if(text1[i] == text2[j]) {
    //          include = 1 + lcs(text1,text2,i+1,j+1,dp);
    //     }

    //         int exclude = 0 + max(lcs(text1,text2,i,j+1,dp),lcs(text1,text2,i+1,j,dp));

    //        dp[i][j] = max(include,exclude);
    //        return dp[i][j];

    // }


//     int bottomup(string text1, string text2) {
//     int n = text1.size(), m = text2.size();
    
//     // Create DP table, initialized with 0
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (text1[i - 1] == text2[j - 1]) {
               
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             } else {
                
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     // LCS length is stored in dp[n][m]
//     return dp[n][m];
// }


   int bottomupso(string text1, string text2) {
     int n = text1.size(), m = text2.size();
    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
        
            if (text1[i - 1] == text2[j - 1]) {
               
                curr[i] = 1 + prev[i - 1];
            } else {
                
                curr[i] = max(curr[i - 1], prev[i]);
            }
            
        }
        prev = curr;
        
    }

    return curr[n];

   }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return bottomupso(text1,text2);
    }