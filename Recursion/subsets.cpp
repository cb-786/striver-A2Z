vector<vector<int>> ans;
    vector<int> subset(vector<int> &nums,vector<int> sub,int i) {
        if(i>=nums.size()) {
              reverse(sub.begin(),sub.end());
                ans.push_back(sub);
                return sub;
        }
         
        subset(nums,sub,i+1);
        sub.push_back(nums[i]);
        subset(nums,sub,i+1);
        

      return sub;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        subset(nums,sub,0);
        return ans;
    }