 int longestBalanced(vector<int>& nums) {

        unordered_set<int> a;
        unordered_set<int> b;
        int ans = 0;
        for(int i = 0 ; i<nums.size();i++) {
            for(int j = i;j<nums.size();j++) {
                if(nums[j]%2 == 0) a.insert(nums[j]);
                else b.insert(nums[j]);

                if(a.size() == b.size()) {
                    ans = max(ans,j-i+1);
                }
            }
            a.clear();
            b.clear();
            
        }
        return ans;
       
    }