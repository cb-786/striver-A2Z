int minOperations(vector<int>& nums) {
        
    int l=0;
    int r=l+2;
    int ans=0;
    int n=nums.size();
    while(l<=nums.size()-3) {
        if(nums[l]==0) {
           nums[l] = (nums[l]^1);
           nums[l+1] = (nums[l+1]^1);
           nums[l+2] = (nums[l+2]^1);
            ans++;
        }

        l++;
        r++;
    }

   if(nums[n-1]==0 || nums[n-2]==0) return -1;

    return ans;

}