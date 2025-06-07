void nextPermutation(vector<int>& nums) {
       
    int i = nums.size()-1;
    while(i>=1 && nums[i-1] >= nums[i]) {
       i--;
    }

    if(i==0) {
       reverse(nums.begin(),nums.end());
       return ;
    }

    else {
       int pivot = i-1;
       while(i<nums.size() && nums[i]>nums[pivot]) {
           i++;
       }
       
       if(i<=nums.size()) {
           swap(nums[pivot],nums[i-1]);
       }

       reverse(nums.begin()+pivot+1,nums.end());
    }

    return ;
 



  


}