vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && arr[s.top()]>arr[i]) {
            s.pop();
        }

        ans[i] = (s.empty()) ? n : s.top();

        s.push(i);
    }
    
    return ans;
}

    vector<int> prev(vector<int> &arr,int n) {
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse =  nextSmallerElement(arr,arr.size());
        vector<int> pse = prev(arr,arr.size());
        
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long freq = (left * right);
            ans = (ans + (freq * arr[i]));
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && arr[s.top()]<arr[i]) {
            s.pop();
        }

        ans[i] = (s.empty()) ? n : s.top();

        s.push(i);
    }
    
    return ans;
}

    vector<int> prevg(vector<int> &arr,int n) {
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxis(vector<int>& arr) {
        vector<int> nge =  nextGreaterElement(arr,arr.size());
        vector<int> pge = prevg(arr,arr.size());
        
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            long long freq = (left * right);
            ans = (ans + (freq * arr[i]));
        }
        return ans;

       
    }
    long long subArrayRanges(vector<int>& nums) {
        long long min = sumSubarrayMins(nums);
        long long max = sumSubarrayMaxis(nums);
        return max-min;
    }