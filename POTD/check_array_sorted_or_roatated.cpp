 bool check(vector<int>& nums) {
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        if(nums == sorted) return true;
        bool ans = false;
        for(int i=1;i<=nums.size();i++) {
              for(int j=0;j<nums.size();j++) {
                if(nums[j] != sorted[(j+i) % nums.size()]) {
                    ans = false;
                    break ;
                }
                else {
                    ans = true;
                }
              }
              if(ans==true) break;
        }

        return ans;
        
    }