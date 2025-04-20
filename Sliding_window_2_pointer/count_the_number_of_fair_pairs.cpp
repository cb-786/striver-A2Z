long long countFairPairs(vector<int>& nums, int lower, int upper) {

    sort(nums.begin(),nums.end());
    long long cntupper = 0;
    int i=0;
    int j=nums.size()-1;
    while(i<j) {
        if(nums[i]+nums[j]<=upper) {
            cntupper += j-i;
            i++;
        }

        else {
            j--;
        }
    }

    i=0;
    j=nums.size()-1;
long long cntlower=0;
     while(i<j) {
         if(nums[i]+nums[j]<lower) {
            cntlower += j-i;
            i++;
        }

        else {
            j--;
        }
     }

     return cntupper-cntlower;
}