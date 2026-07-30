int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++) {
            if((i/8)==0) {
                ans++;
                continue;
            }
            ans+=(i/8)+1;
        }
        return ans;
    }