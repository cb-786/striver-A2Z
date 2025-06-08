int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    int pre =0;
    int ans=0;
    map[0]=1;
    for(int i=0;i<nums.size();i++) {
        pre += nums[i];
        auto it = map.find(pre-k);
        if(it!=map.end()) {
            ans += it->second;
        }
        map[pre] ++;
    }
    return ans;
}