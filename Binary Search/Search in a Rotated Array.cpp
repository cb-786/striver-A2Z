int search(vector<int>& nums, int target) {
          int s = 0;
    int e = nums.size() - 1;

    // Handle edge cases
    if (nums.empty()) return -1; 
    

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] > nums[e]) {
            // Pivot must be in the right part
            s = mid + 1;
        } else {
            // Pivot must be in the left part
            e = mid;
        }
    }
   int pivot =s;
    //now we apply binary search by breaking the given array about the pivot
    int s1=0;
    int e1=pivot-1;
    while(s1<=e1) {
        int mid1 = s1 + (e1-s1)/2;

        if(nums[mid1] == target) {
            return mid1;
        }


        if(nums[mid1] < target) {
            s1 = mid1 +1;
        }

        if(nums[mid1]>target) {
            e1 = mid1-1;
        }
    }



     int s2=pivot;
    int e2=nums.size()-1;
    while(s2<=e2) {
        int mid2 = s2 + (e2-s2)/2;

        if(nums[mid2] == target) {
            return mid2 ;
        }


        if(nums[mid2] < target) {
            s2 = mid2 +1;
        }

        if(nums[mid2]>target) {
            e2 = mid2-1;
        }
    }

    return -1;
}