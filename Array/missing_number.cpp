int missingNumber(vector<int>& nums) {
    int sum=0;
    int ideal=0;
    for(int i=0;i<nums.size();i++) {
            ideal+=i;
            sum+=nums[i];
    }
    ideal+=nums.size();
    return ideal-sum;
}