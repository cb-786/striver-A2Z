 bool can(vector<int> &stalls,int k, int mid) {
        int cows = 1,last = stalls[0];
        
        for(int i=1;i<stalls.size();i++) {
            if(stalls[i] - last >= mid) {
                cows ++;
                last = stalls[i];
            }
            
            
        }
        
        if(cows >= k) return 1;
        
        return 0;
    }
    
    
    
    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls.back();
        int mid = low + (high -low)/2;
        
        while(low <= high) {
            mid = low + (high-low)/2;
            
            if(can(stalls,k,mid)) {
                low = mid+1;
            } else {
                high = mid -1;
            }
        }
        
        return high;
        
    }