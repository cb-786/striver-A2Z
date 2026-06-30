class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if (nums.empty()) return 0;
    
    unordered_map<int,int> s;
    for(const auto &ele:nums) {
            s[ele]++;
    }
    int fans = 1;
    
    for (auto [k,val] : s) {
        if (s.find(k - 1) == s.end()) {
            int c = k;
            int ans = 1;
            
            while (s.find(c + 1) != s.end()) {
                c++;
                ans++;
            }
            fans = max(fans, ans);
        }
    }
    return fans;
    }
};