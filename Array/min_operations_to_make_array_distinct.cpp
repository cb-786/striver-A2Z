int minimumOperations(vector<int>& nums) {
    int i=0;
    int ans=0;
    while(true) {
        int flag2=0;
        for(int j=i;j<nums.size()-1;j++) {
            for(int k=j+1;k<nums.size();k++) {
                    if(nums[j]==nums[k]) {
                        flag2=1;
                        break;
                    }
            }
        }

        if(flag2) {
            ans++;
            if(i+3<nums.size())
            i+=3;

            else {
                return ans;
            }

        }

        else {
            break;
        }
    }

    return ans;
}