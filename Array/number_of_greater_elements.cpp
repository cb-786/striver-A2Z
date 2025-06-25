vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    // write your code here
    vector<int> ans;
    for(int i=0;i<queries;i++) {
        int cnt=0;
        int ind = indices[i];
        for(int j=ind;j<arr.size();j++) {
            if(arr[j] > arr[ind] ) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}