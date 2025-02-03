//    int rec(string word1,string word2,int i,int j) {
//       if(i==word1.size()) {
//         return word2.size()-j;
//       }

//       if(j==word2.size()) {
//         return word1.size()-i;
//       }

//       int ans =0;
//       if(word1[i] == word2[j]) {
//        ans = rec(word1,word2,i+1,j+1);
//       }

//       if(word1[i] != word2[j]) {
//        int ins = 1 + rec(word1,word2,i,j+1);
//        int del = 1 + rec(word1,word2,i+1,j);
//        int upd = 1 + rec(word1,word2,i+1,j+1);
//         ans = min(ins,min(del,upd));
//       }
    
    
//     return ans;
//    }


//    int topdown(string word1,string word2,int i,int j,vector<vector<int>> &dp) {
//            if(i==word1.size()) {
//         return word2.size()-j;
//       }

//       if(j==word2.size()) {
//         return word1.size()-i;
//       }

//       if(dp[i][j] !=-1) {
//         return dp[i][j];
//       }

//       int ans =0;
//       if(word1[i] == word2[j]) {
//        ans = topdown(word1,word2,i+1,j+1,dp);
//       }

//       if(word1[i] != word2[j]) {
//        int ins = 1 + topdown(word1,word2,i,j+1,dp);
//        int del = 1 + topdown(word1,word2,i+1,j,dp);
//        int upd = 1 + topdown(word1,word2,i+1,j+1,dp);
//         ans = min(ins,min(del,upd));
//       }
    
    
//      dp[i][j] = ans;
//      return dp[i][j];
//    }


//    int bottomup(string word1,string word2) {
//      int n = word1.size(),m=word2.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
//     for(int i=0;i<=m;i++) {
//         dp[n][i] = m-i;
//     }

//     for(int i=0;i<=n;i++) {
//         dp[i][m] = n-i;
//     }


//     for(int i=n-1;i>=0;i--) {
//         for(int j=m-1;j>=0;j--) {
//         int ans =0;
          
//             if(word1[i] == word2[j]) {
//                 ans = dp[i+1][j+1];
//                 }
        
     

//       if(word1[i] != word2[j]) {
//        int ins = 1 + dp[i][j+1];
//        int del = 1 + dp[i+1][j];
//        int upd = 1 + dp[i+1][j+1];
//         ans = min(ins,min(del,upd));
//       }

//       dp[i][j] = ans; 
//         }
//     }

//     return dp[0][0];

//    }


   int bottomupso(string word1, string word2) {
    int n = word1.size(),m=word2.size();
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

     for(int i=0;i<=n;i++) {
        next[i] = n-i;
    }

for(int j=m-1;j>=0;j--) {
    curr[n] = m-j;
      for(int i=n-1;i>=0;i--) {
        
        int ans =0;
          
            if(word1[i] == word2[j]) {
                ans = next[i+1];
                }
        
     

      if(word1[i] != word2[j]) {
       int ins = 1 + next[i];
       int del = 1 + curr[i+1];
       int upd = 1 + next[i+1];
        ans = min(ins,min(del,upd));
      }

      curr[i] = ans;
      
        }
next = curr;
   }

   return next[0];

   }


    int minDistance(string word1, string word2) {
        // int n = word1.size(),m=word2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        return bottomupso(word1,word2);
    }