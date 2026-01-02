class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        int freq = INT_MIN;
        int ans = -1;
        for(const auto &ele :nums) {
            map[ele]+=1;
            // cout << ele << " " << map[ele] << endl;
            if(freq < map[ele])
            {   
                freq = map[ele];
                ans = ele;
                }
        }
        return ans;
    }
};