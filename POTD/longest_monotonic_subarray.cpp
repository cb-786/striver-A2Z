int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 1;
        for(int i=0;i<nums.size()-1;i++) {
            count =1;
            for(int j=i;j<nums.size()-1;j++) {
                if(nums[j]<nums[j+1]) {
                while(j<nums.size()-1  && nums[j]<nums[j+1]) {
                    count++;
                    j++;
                }
                maxi=max(maxi,count);
                break;
            }

            if(nums[j]>nums[j+1]) {
                while(j<nums.size()-1 && nums[j]>nums[j+1]) {
                    count++;
                    j++;
                }
                maxi=max(maxi,count);
                break;
            }
            }

            
        }

        if(maxi == INT_MIN) return 1;

        return maxi;
    }