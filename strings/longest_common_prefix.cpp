 string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int j = 0;
        int i=0;
        int minl = strs[0].size();
        while(j<minl)  {
            for(i=0;i<strs.size()-1;i++) {
                minl = min((long long)minl,(long long)strs[i].size());
                if(j>=minl) break;

               if(strs[i][j] == strs[i+1][j]) continue ;
               else return ans;

            }
            ans.push_back(strs[i][j]);
            j++;
            
        }
        return ans;
    }