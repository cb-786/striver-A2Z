int maxAbsoluteSum(vector<int>& nums) {
    int max_sum = nums[0]; 
    int min_sum = nums[0]; 
    int res = abs(nums[0]); 

    for (int i = 1; i < nums.size(); i++) {
        max_sum = max(nums[i], max_sum + nums[i]);  
        min_sum = min(nums[i], min_sum + nums[i]);  

        res = max(res, max(abs(max_sum), abs(min_sum)));  
    }

    return res;
}