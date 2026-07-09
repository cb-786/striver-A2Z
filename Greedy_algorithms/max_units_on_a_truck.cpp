int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b) {
        if(a[1]==b[1]) {
            return a[0]>b[0];
        }
        return a[1]>b[1];
     } );
        int ans=0;
        for(const auto &ele:boxTypes) {
            if(truckSize==0) return ans;
            if(ele[0]<truckSize) {
                ans+=(ele[0]*ele[1]);
                truckSize-=ele[0];
            }
            else {
                ans+=(truckSize*ele[1]);
                return ans;
            }
        }
        return ans;
    }