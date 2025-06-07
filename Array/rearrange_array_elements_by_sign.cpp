vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    for(auto ele:nums) {
        if(ele>0) {
            pos.push_back(ele);
        }
        else {
            neg.push_back(ele);
        }
    }
    nums.clear();
    for(int i=0;i<2*pos.size();i++) {
        if(i%2==0) {
            nums.push_back(pos[i/2]);
        }
        else {
            nums.push_back(neg[i/2]);
        }
    }
    return nums;
    

    
}