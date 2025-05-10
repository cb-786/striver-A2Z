int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans=INT_MIN;
    int i=0;
    int j=0;
    while(j<nums.size()) {

       
        while(j<nums.size() && nums[j]==1) {
            j++;
            
        }
        ans=max(ans,j-i);
        j++;
        i=j;
        
    }
    return ans;
}