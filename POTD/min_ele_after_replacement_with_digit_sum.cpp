class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto &ele : nums) {
            int csum = 0;
            while(ele!=0) {
                // int csum = 0;
                int cd = ele%10;
                ele/=10;
                csum += cd;
            }
            ans = min(ans,csum);
            
        }
        return ans;
    }
};