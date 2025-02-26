string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
        
        // Create DP table, initialized with 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                   
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    
               string ans="";
              int i=n;
              int j=m;
               while(i>0 && j>0) {
                     if(str1[i-1]==str2[j-1]) {
                              ans.push_back(str1[i-1]);
                              i--;
                              j--;
                     }
    
                    else if(i>0 && dp[i-1][j]==dp[i][j] && j>0 && dp[i][j-1]!=dp[i][j]) {
                        ans.push_back(str1[i-1]);
                        i--;
                     }
    
                    else if(i>0 && dp[i-1][j]!=dp[i][j] && j>0 && dp[i][j-1]==dp[i][j]) {
                        ans.push_back(str2[j-1]);
                        j--;
                     }
    
                     else {
                        if(i>0) {
                            ans.push_back(str1[i-1]);
                            i--;
                        }
                        
                     }
               }
    
               if(i>0 || j>0) {
                if(i==0 && j!=0) {
                         while(j!=0) {
                    ans.push_back(str2[j-1]);
                    j--;
                }
                }
                
              if(j==0 && i!=0) {
                  while(i!=0) {
                    ans.push_back(str1[i-1]);
                       i--;
                }
              }
                
               }
    
               reverse(ans.begin(),ans.end());
               return ans;
                      
          }