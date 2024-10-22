int singleNonDuplicate(vector<int>& nums) {
        int s =0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;


    while(s<e) {



        mid = s+(e-s)/2;


        if(mid == 0) {
               if(nums[mid+1] != nums[mid]) {
                return nums[mid];
               }

               else {
                break;
               }
        }




        if((nums[mid+1] != nums[mid]) && (nums[mid-1] != nums[mid])) {
            return nums[mid];
        }
        if((nums[mid+1] == nums[mid]) && (mid%2==0)) {
            s=mid+1;
        }

        if((nums[mid+1] == nums[mid]) && (mid%2!=0)) {
            e=mid-1;
        }

        if((nums[mid-1] == nums[mid]) && (mid%2==0)) {
            e=mid-1;
        }

        if((nums[mid-1] == nums[mid]) && (mid%2!=0)) {
            s=mid+1;
        }
    }

     return nums[s];
   


    }