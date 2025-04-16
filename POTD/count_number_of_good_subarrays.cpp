long long countGood(vector<int>& nums, int k) {
    int l=0;
    long long r=-1;
    long long n = nums.size();
    long long ans=0;
    int s=0;
    unordered_map<int,int> cnt;
    while(l<n) {
        while(s<k && r+1<n) {
            r++;
            s+=cnt[nums[r]];
            cnt[nums[r]]++;
        }

        if(s>=k) {
            ans+=n-r;
        }

        
        --cnt[nums[l]];
        s-=cnt[nums[l]];
        l++;
    }

    return ans;



}