long long solve(vector<int>& bt) {
        long long sum =0;
        long long ans=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size()-1;i++) {
            sum+=bt[i];
            ans+=sum;
        }
        return ans/bt.size();
    }