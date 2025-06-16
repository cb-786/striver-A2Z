vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && arr[s.top()]>=arr[i]) {
            s.pop();
        }

        ans[i] = (s.empty()) ? -1 : s.top();

        s.push(i);
    }
    
    return ans;
}

   vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for(int i=0;i<n;i++) {
        while(!s.empty() && arr[s.top()]>=arr[i]) {
            s.pop();
        }

        ans[i] = (s.empty()) ? -1 : s.top();

        s.push(i);
    }
    
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        vector<int> dummy;
        dummy.push_back(-1);
        for(const auto& ele : heights) {
            dummy.push_back(ele);
        }
        dummy.push_back(0);

        vector<int> p =  prevSmallerElement(dummy,dummy.size());
        vector<int> n =  nextSmallerElement(dummy,dummy.size());
        
        int ans = INT_MIN;
        for(int i=1;i<n.size()-1;i++) {
            n[i] = n[i]-p[i] -1;
            ans= max(ans,heights[i-1]*n[i]);
        }
        return ans;

        
    }