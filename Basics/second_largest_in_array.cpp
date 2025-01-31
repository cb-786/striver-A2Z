vector<int> removeDuplicates(const vector<int>& arr) {
    vector<int> result;
    unordered_set<int> seen; // To keep track of elements we've already added

    for (int num : arr) {
        if (seen.find(num) == seen.end()) { // If the number is not in the set
            result.push_back(num);          // Add it to the result
            seen.insert(num);               // Mark it as seen
        }
    }

    return result;
}


    int getSecondLargest(vector<int> &arr) {
        
       arr = removeDuplicates(arr);
        
        for(int j=1;j<=2;j++) {
            for(int i=0;i<arr.size()-1;i++) {
            if(arr[i]>=arr[i+1]) {
                swap(arr[i],arr[i+1]);
            }
        }
        }
        
        if(arr.size()<2) return -1;
        
        return arr[(arr.size()-2)];
        
    }