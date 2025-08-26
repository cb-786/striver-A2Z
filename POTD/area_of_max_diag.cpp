int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int maxd = 0;
        int ans = INT_MIN;
       for(const auto &row : dimensions) {
          int l = row[0];
          int b = row[1];
          int currd = l*l + b*b;
            if(currd == maxd) {
                ans = max(l*b,ans);
            }
            else if(currd > maxd) {
                ans = l*b;
                maxd = currd;
            }
          
       }

       return ans;

    }