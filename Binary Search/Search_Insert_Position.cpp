int searchInsert(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        int mid = s+ (e-s)/2;
          int n  = nums.size();
           if( target > nums[n-1]) {

                   return n;

           }

           if(target<nums[0]) {

            return 0;

           }


          while(s<=e) {

           mid = s+ (e-s)/2;

            if(target==nums[mid]) {
                return mid;
            }

            if(nums[mid]<target && target<nums[mid+1]) {
                   return mid+1;
            }
                    
                    if(nums[mid] < target) {
                                s=mid+1;
                    }

                    if(target<nums[mid]) {
                        e=mid-1;
                    }
          }

          return -1;




    }