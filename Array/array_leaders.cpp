vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=arr.size()-1;i>=0;i--) {
        if(arr[i]>=maxi) {
            ans.push_back(arr[i]);
        }
        
        maxi = max(maxi,arr[i]);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
    
}