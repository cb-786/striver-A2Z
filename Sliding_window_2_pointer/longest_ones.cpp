int longestOnes(vector<int>& nums, int k) {
    int i=0;
    int j=0;
    int ans=INT_MIN;
    while(j<nums.size()) {

            if(nums[j]==0 && k==0) {
                while(k==0) {
                    if(nums[i]==0) {
                        i++;
                        k++;
                        break;
                    }
                    i++;
                }
            }


            if(nums[j]==0 ) {
                k--;
                j++;
            }

            while(j<nums.size() && nums[j]==1) {
                j++;
            }


            ans = max(ans,j-i);

    }
    return ans;
}