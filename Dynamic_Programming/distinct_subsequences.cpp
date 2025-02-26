vector<vector<int>> dp; 

int rec(string &s, string &t, int i, int j) {
    
    if (j == t.size()) return 1;  
    if (i == s.size()) return 0;  

    
    if (dp[i][j] != -1) return dp[i][j];

    
    int ways = rec(s, t, i + 1, j); 
    
    if (s[i] == t[j]) {
        ways += rec(s, t, i + 1, j + 1); 
    }

    return dp[i][j] = ways; 
}

int numDistinct(string s, string t) {
    dp.assign(s.size(), vector<int>(t.size(), -1)); 
    return rec(s, t, 0, 0);
}