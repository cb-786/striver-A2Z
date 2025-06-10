int maxLen(vector<int>& arr) {
    unordered_map<int,int> map;
    map[0]= -1;
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        auto it = map.find(sum);
        if(it == map.end()) {
            map[sum] = i;
        }
        
        else {
            int j = it->second;
            ans = max(ans,i-j);
        }
        
    }
    return (ans==INT_MIN) ? 0 : ans;
}