bool can(vector<int> & nums,int m,int k, int mid) {\
            int c = k;
            int poss = 0;
            int f=0;
        for(int i=0;i<nums.size();i++) {
            
                while(i<nums.size() &&  c>0 && nums[i] <= mid) {
                c--;
                i++;
                f=1;
                
                }
                if(c==0) poss++;
                c=k;
                if(f) i--;
                f=0;
        }
        if(poss >= m) return 1;

        return 0;
    }








    int minDays(vector<int>& bloomDay, int m, int k) {
        long long poss = (long long)m * (long long)k;
        if(poss > bloomDay.size()) return -1;

        int maxi = INT_MIN;
        for(const auto& ele : bloomDay) {
            maxi = max(maxi,ele);
        }

        int s = 0;
        int e = maxi;
        int mid = s + (e-s)/2;

        while(s<e) {
            
            mid = s + (e-s)/2;

            if(can(bloomDay,m,k,mid)) {
                e=mid;
            } else {
                s=mid+1;
            }
        }
        return e;
    }