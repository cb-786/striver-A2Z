bool can(vector<int> &nums, int thr,int mid) {
    
    int sum = 0;

    for(const auto & ele : nums) {
        float dividend = ele;
        float divisor = mid;
        int result = ceil(dividend / divisor);
        sum += result;
    }
    if(sum<=thr) return 1;
    return 0;
    }







    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(const auto & ele: nums) {
            maxi = max(maxi,ele);
        }


        int s = 1;
        int e = maxi;
        int mid = s + (e-s)/2;

        while(s<e) {
            mid = s + (e-s)/2;

            if(can(nums,threshold,mid)) {
                e=mid;
            }
            else {
                s=mid+1;
            }
        }
        return e;
    }