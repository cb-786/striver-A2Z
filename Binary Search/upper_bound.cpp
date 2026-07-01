int upperBound(vector<int>& arr, int target) {
        // code here
        int s=0;
        int e = arr.size()-1;
        while(s<e) {
            int mid=s+(e-s)/2;
            if(arr[mid]>target) {
                e=mid;
            }
            else {
                s=mid+1;
            }
        }
        if(arr[e]<=target) return arr.size();
        return e;
    }