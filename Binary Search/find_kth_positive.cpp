int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size();
    if (arr[0] > k) return k; // if k-th missing is before the first element

    int s = 0, e = n - 1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        // Number of missing numbers before arr[mid] is arr[mid] - (mid + 1)
        int missing = arr[mid] - (mid + 1);
        
        if (missing < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    // After loop, s is the index of the first number where missing >= k
    // So the k-th missing number is between arr[s-1] and arr[s]
    return s + k;
    }