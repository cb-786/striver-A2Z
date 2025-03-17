bool divideArray(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i=0;
    int e=0;
    while(i<nums.size()-1) {
        if(nums[i]==nums[i+1]) {
            e++;
            i++;

        }

        else {
            if((e+1)%2!=0) return false;

            e=0;
            i++; 
        }

    }
    if((e+1)%2!=0) return false;


    return true;
}