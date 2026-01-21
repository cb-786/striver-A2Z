vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
       for(auto &ele : nums) {
        if(ele%2==0) {
            ans.push_back(-1);
            continue;
        }
            int idx = 0;
            while((ele >> idx) & 1) {
                idx++;
            }
            // cout << idx << endl;
            if(idx == 1) {
                ele = ele >> 1;
                ans.push_back(ele << 1);
                continue;
            }
            ans.push_back(ele ^ ((1 << (idx-1))));
       }
       return ans;
    }