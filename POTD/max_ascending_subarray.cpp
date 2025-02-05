int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1) {
            return nums[0];
        }
        int i=0;
        int j=i+1;
        int maxi =INT_MIN;
        int count=0;

       

        while(i<nums.size() && j<nums.size()) {
                   if(nums[i]<nums[j]) {
                    count+=nums[i];
                    i++;
                    j++;
                    if(i==nums.size()-1) {
                        count+=nums[i];
                        maxi = max(maxi,count);
                        return maxi;
                    }
                    if(nums[i]>=nums[j]) {
                        count+=nums[i];
                    }
                   }

                   else {
                    
                    maxi = max(maxi,count);
                    maxi = max(maxi,nums[i]);
                    count=0;
                    i=j;
                    j=i+1;

                    if(j>nums.size()-1) {
                        if(nums[i]>maxi) {
                            return nums[i];
                        }
                        break;
                    }
                   }
        }
        return maxi;
    }