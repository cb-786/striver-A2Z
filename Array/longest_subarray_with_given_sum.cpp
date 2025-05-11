int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> map;
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == k) {
            ans = max(ans, i + 1);
        }

        int rem = sum - k;
        if (map.find(rem) != map.end()) {
            ans = max(ans, i - map[rem]);
        }

        // Only store the first occurrence of sum
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }

    return ans;
}