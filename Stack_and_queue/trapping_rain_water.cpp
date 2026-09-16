 vector<int> nge(vector<int> &nums) {
        vector<int> ans;
        int maxi=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--) {
                maxi=max(maxi,nums[i]);
                ans.push_back(maxi);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


    vector<int> pge(vector<int> &nums) {
        vector<int> ans;
        int maxi=INT_MIN;
        for(const auto &ele:nums) {
                maxi=max(maxi,ele);
                ans.push_back(maxi);
        }
        return ans;
    }



    int trap(vector<int>& height) {
        vector<int> n = nge(height);
        vector<int> p = pge(height);
        int ans=0;
        for(int i=0;i<height.size();i++) {
            int cs = min(n[i],p[i])-height[i];
            ans+=(cs<=0) ? 0 : cs;
        }
        return ans;
    }