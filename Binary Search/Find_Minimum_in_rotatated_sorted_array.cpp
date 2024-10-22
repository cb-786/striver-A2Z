int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;


        //deal with edge cases
        if(nums.size()==0) {
            return -1;
        }

        if(nums.size()==1) {
            return nums[0];
        }


        //find the pivot index
        while(s<e) {
            mid=s+(e-s)/2;
            if(nums[mid]>nums[e]) {
                s=mid+1;
            }

            else {
                e=mid;
            }
        }

        return nums[s];




    }