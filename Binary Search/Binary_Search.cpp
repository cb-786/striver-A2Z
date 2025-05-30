int search(vector<int>& nums, int target) {
        int s =0;
        int e = nums.size() -1;
        int mid = s+ (e-s)/2;

          if(nums.size() == 1 && target == nums[0]) return 0;

        while(s<=e) {
                 mid = s+ (e-s)/2;
                 if(nums[mid] == target) return mid;

                 if(nums[mid]>target) {
                    e=mid-1;
                 }

                 else {
                    s=mid+1;
                 }
        }

        return -1;
    }
};