bool search(vector<int>& nums, int target) {
        int s =0;
        int e = nums.size()-1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            // cout << s << " " << e << " " << mid << " " << nums[mid] << endl;
            if(nums[mid]==target) return 1;
            if(nums[s]==target || nums[e]==target) return 1;

            if(nums[mid]==nums[s] && nums[s]==nums[e]) {
                s++;
                e--;
                 continue;
            }

            if(nums[mid]<=nums[e]) {
                if(nums[mid]<target && nums[e]>target) {
                    s=mid+1;
                }
                else {
                    e=mid-1;
                }
            }
            else {
                if(nums[mid]>target && nums[s]<target) {
                    e=mid-1;
                }
                else {
                    s=mid+1;
                }
            }
        }
        return 0;
    }