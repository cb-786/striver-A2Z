int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> map;
        int ans =0;
        for(const auto &ele:nums) {
            map[ele]++;
        }
        int fans=1;
        for(auto [ele,val]:map) {
            if(ele==1) {
                if(val%2==0) val--;
                fans= max(fans,val);
                continue;
            }
            if(val<2) {continue;}
            ans=2;
            long long cc=ele;
            while(1) {
                cc= cc*cc;
                if(map.count(cc) && map[cc]>=2) {
                    ans+=2;
                    fans=max(ans,fans);
                    continue;
                }
                if(map.count(cc) && map[cc]==1) {
                    ans+=1;
                    fans=max(ans,fans);
                    break;
                }
                break;
            }
        }
        return (fans%2==0) ? fans-1: fans;
    }