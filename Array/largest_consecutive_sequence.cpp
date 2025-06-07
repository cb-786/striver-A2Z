int longestConsecutive(vector<int>& arr) {
    if (arr.empty()) return 0;

    sort(arr.begin(), arr.end());

    int ans = 1;
    int curr_len = 1;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) {
            // Skip duplicates
            continue;
        }
        else if (arr[i] == arr[i - 1] + 1) {
            // Consecutive element
            curr_len++;
        }
        else {
            // Sequence broken
            curr_len = 1;
        }

        ans = max(ans, curr_len);
    }

    return ans;
}