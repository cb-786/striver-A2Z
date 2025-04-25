int numberOfSubarrays(vector<int>& nums, int k) {
    int ansl=0;
    int i=0;
    int j=0;
    int cnt=0;
    while(j<nums.size()) {
        if(nums[j]%2==1) {
            cnt++;
        }
        j++;

        while(cnt>k-1) {
            if(nums[i]%2==1) {
                cnt--;
            }
            i++;
        }

        
            ansl+=j-i;
        
    }

    int ansr=0;
     i=0;
     j=0;
     cnt=0;
    while(j<nums.size()) {
        if(nums[j]%2==1) {
            cnt++;
        }
        j++;

        while(cnt>k) {
            if(nums[i]%2==1) {
                cnt--;
            }
            i++;
        }

       
            ansr+=j-i;
        
    }
    return ansr-ansl;
}