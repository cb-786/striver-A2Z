bool isBSTTraversal(vector<int>& arr) {
        vector<int> sorted;
        sorted = arr;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++) {
            if(arr[i]==arr[i+1]) {
                return false;
            }
        }
        
        
        if(arr==sorted) return true;
        
        return false;
    }