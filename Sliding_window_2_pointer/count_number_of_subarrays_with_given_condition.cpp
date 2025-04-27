int countSubarrays(vector<int>& nums) {
    int ans=0;
    int i=0;
    int j=2;
    while(j<nums.size()) {
        if((float)nums[i]+(float)nums[j] == (float)nums[i+1]/2) ans++;

        i++;
        j++;
    }
    return ans;
}