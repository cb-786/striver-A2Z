int lowerBound(vector<int>& arr, int target) {
        int s= 0;
        int e = arr.size()-1;
        while(s<e) {
            int mid = s+(e-s)/2;
            
            
            if(target<=arr[mid]) {
                e=mid;
            }
            
            else {
                s=mid+1;
            }
        }

        
        if(arr[s]<target) return arr.size();
        return s;
    }