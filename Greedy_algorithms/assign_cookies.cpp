int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        for(int i=0;i<s.size();i++) {

            if(count > g.size()-1) break ;

            if(s[i]>=g[count]) {
                count++;
                
            }
        }
        return count;
    }