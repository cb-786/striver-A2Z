int rec(string &s1,string &s2,int i,int j,int &ans,vector<vector<int>> &dp) {
    int m=s1.size(),n=s2.size();
    if(i>=m || j>=n) {
        return ans;
    } 
    
    
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    
    int include=0;
    if(s1[i]==s2[j]) {
        int cnt =1;
      int tmp1 = i;
      int tmp2 =    j;
      tmp1++;
      tmp2++;
        while(s1[tmp1]==s2[tmp2] && tmp1<m && tmp2<n) {
            if(tmp1<m && tmp2<n) cnt++;
            tmp1++;
            tmp2++;
            
        }
        ans = max(ans,cnt);
        dp[i][j] = ans;
       
    }
    
    
    include = max(rec(s1,s2,i+1,j,ans,dp),rec(s1,s2,i,j+1,ans,dp));
    dp[i][j] = ans;
    return dp[i][j];
    
    
}



int bottomup(string &s1,string &s2) {
    int m = s1.size(), n = s2.size();

vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Initialize DP table
int ans = 0; // To store the maximum length of common substring

// Loop in reverse order, as per the top-down recursion pattern
for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) { 
            int cnt = 1;
            int tmp1 = i + 1, tmp2 = j + 1;
            
            while (tmp1 < m && tmp2 < n && s1[tmp1] == s2[tmp2]) {
                cnt++;
                tmp1++;
                tmp2++;
            }

            dp[i][j] = cnt;
            ans = max(ans, cnt);
        }

        // Equivalent to max(rec(s1,s2,i+1,j,ans,dp), rec(s1,s2,i,j+1,ans,dp))
        dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
    }
}

return ans;
}







int longestCommonSubstr(string& s1, string& s2) {
    return bottomup(s1, s2);
    
    
}