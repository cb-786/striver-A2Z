int totalElements(vector<int> &arr) {
    int totcount = 0;
    unordered_map<int, int> freq;
    int i = 0, j = 0;
    int ans = INT_MIN;

            while (j < arr.size()) {
        if(freq[arr[j]]==0) totcount++;
                freq[arr[j]]++;
                j++;
                
                
        if (totcount > 2) {
            while (i <= j && totcount > 2) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    totcount--;
                }
                i++;
            }
        }

        while (j < arr.size() && totcount < 2) {
            if (freq[arr[j]] == 0) {
                totcount++;
            }
            freq[arr[j]]++;
            j++;
        }

        ans=max(ans,j-i);
        
    }

    return (ans==INT_MIN) ? 0 : ans;
}