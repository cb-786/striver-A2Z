void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        while (r < n && r < k + 1) {
            pq.push(arr[r++]);
        }

        while (!pq.empty()) {
            arr[l++] = pq.top();
            pq.pop();
            if (r < n) {
                pq.push(arr[r++]);
            }
        }

        // return arr; // if required by the platform
            
            
            
        
    }