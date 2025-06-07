void rec(vector<int> &nums,vector<vector<int>> &ans,int l,int r) {
    if(l==r) {
        ans.push_back(nums);
        return ;
    }

    for(int i=l;i<=r;i++) {
        swap(nums[l],nums[i]);
        rec(nums,ans,l+1,r);
        swap(nums[i],nums[l]);
    }
}



vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    rec(nums,ans,0,nums.size()-1);
    return ans;
}