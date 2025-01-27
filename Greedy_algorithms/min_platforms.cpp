int findPlatform(vector<int>& arr, vector<int>& dep) {
       sort(arr.begin(), arr.end());
sort(dep.begin(), dep.end());

int i = 0;   // Pointer for arrival times
int j = 0;   // Pointer for departure times
int ans = 0; // Maximum number of platforms required
int cnt = 0; // Current number of platforms needed

while (i < arr.size() && j < dep.size()) {
    if (arr[i] <= dep[j]) {
        // A train arrives before the last one departs
        cnt++;
        i++;
        ans = max(ans, cnt);  // Update max platforms if needed
    } 
    else  {
        // A train departs before the next one arrives (or exactly at the same time)
        cnt--;
        j++;
    }
}

return ans;

    }