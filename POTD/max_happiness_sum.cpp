long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans = 0;
        int i =0;
        while(k!=0) {
            ans+=((long long)happiness.back()-(long long)i>=0) ? (long long)happiness.back()-(long long)i : 0;
            k--;
            i++;
            happiness.pop_back();
        }
        return ans;
    }