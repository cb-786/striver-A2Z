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


   int minInsertions(string s) {
               string s2 =s;
               reverse(s2.begin(),s2.end());
               int lps = bottomupso(s,s2);
               int len = s.size();
               return len-lps;     
   }