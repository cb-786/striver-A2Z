int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int l = 0;
        int r=0;
        int curr = 0;
        int ans = 1;

        while(r<nums.size()) {
            if(map[nums[r]] == 0) {
                curr+=nums[r];
                ans = max(ans,curr);
                map[nums[r]]++;
                r++;
            }

            else {
                while(l<=r && map[nums[r]] != 0) {
                    curr-=nums[l];
                    map[nums[l]]--;
                    l++;
                }
            }
        }
        return ans;

    }