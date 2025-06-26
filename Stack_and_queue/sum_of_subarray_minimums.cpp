int mod = 1e9+7;
    

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

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse =  nextSmallerElement(arr,arr.size());
        vector<int> pse = prev(arr,arr.size());
        
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long freq = (left * right) % mod;
            ans = (ans + (freq * arr[i]) % mod) % mod;
        }
        return ans;

       
    }