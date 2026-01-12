class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i =0 ;i<points.size()-1;i++) {
            
            int i1 = points[i][0];
            int j1 = points[i][1];
            int i2 = points[i+1][0];
            int j2 = points[i+1][1];

            
               int di = abs(i1 - i2);
               int dj = abs(j1 - j2);

               while(di != 0 && dj != 0) {
                di--;
                dj--;
                ans++;
               }

               ans+=di+dj;
            
            
        }
        return ans;
    }
};