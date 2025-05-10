void moveZeroes(vector<int>& nums) {
    int j=0;
    while(j<nums.size() && nums[j]!=0) {
        j++;
    }

    for(int i=j+1;i<nums.size();i++) {
        if(nums[i]!=0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }

}