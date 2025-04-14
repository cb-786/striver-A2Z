void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    vector<int> tmp;
    int pivot = nums.size()-k;
    for(int i=pivot;i<nums.size();i++) {
        tmp.push_back(nums[i]);
    }

    for(int i=0;i<pivot;i++) {
        tmp.push_back(nums[i]);
    }

    nums=tmp;
}