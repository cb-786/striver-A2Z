int findKRotation(vector<int> &arr) {
        int s =0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        
        if(arr.size()==0) {
            return -1;
        }
        
        
        
        while(s<e) {
            mid = s+(e-s)/2;
            if(arr[mid]>arr[e]) {
                s=mid+1;
            }
            
            else {
                e=mid;
            }
        }
        
        return s;
        
        
    }