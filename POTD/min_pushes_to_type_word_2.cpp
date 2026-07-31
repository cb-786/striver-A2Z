int minimumPushes(string word) {
        int curr=0;
        int ans=0;
        vector<pair<int,char>> vp(26,{0,'-1'});
        for(const auto &ele:word) {
            vp[ele-'a'].first+=1;
            vp[ele-'a'].second=ele;
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        vector<int> hash(26,-1);
        for(const auto &ele:vp) {
            if(ele.first!=0 && hash[ele.second-'a']==-1) {
              hash[ele.second-'a']=(curr/8)+1;
              curr++;
            }
        }
        for(const auto &ele:vp) {
            if(ele.first!=0) {
                ans+=hash[ele.second-'a']*ele.first;
            } 
        }
        return ans;
    }