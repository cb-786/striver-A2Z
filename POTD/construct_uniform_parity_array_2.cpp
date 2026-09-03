bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        for(const auto &ele:nums1) {
            mini=min(mini,ele);
        }
        if(mini&1==1) return 1;
        for(const auto &ele:nums1) {
            if((ele&1)==0) {
                continue;
            } else {
                return 0;
            }
        }
        return 1;
    }