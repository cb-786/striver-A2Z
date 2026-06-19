int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int s=0;
        for(const auto &ele:gain) {
            s+=ele;
            ans=max(ans,s);
        }
        return ans;
    }