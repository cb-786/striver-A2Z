class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()<=2) {
            return accumulate(cost.begin(),cost.end(),0);
        }
        int ans = 0;
        int i = 0;
        sort(cost.begin(),cost.end());
        for(i = cost.size()-1;i>=2;i=i-3) {
            ans+=cost[i] + cost[i-1];
        }
        if(i>=0) {
            // cout << i << endl;
            while(i>=0) {
                ans += cost[i];
                i--;
            }
        }
        return ans;
    }
};