bool subsetpresent(int n, int k, vector<int> &a, int sum, int i, vector<vector<int>> &dp) {
    // Base cases
    if (sum == k) return true;   // Found a subset with the required sum
    if (i >= n || sum > k) return false; // Index out of bounds or sum exceeds target

    // Check if the result is already computed
    if (dp[i][sum] != -1) return dp[i][sum];

    // Include the current element
    bool include = subsetpresent(n, k, a, sum + a[i], i + 1, dp);
    // Exclude the current element
    bool exclude = subsetpresent(n, k, a, sum, i + 1, dp);

    // Store the result in the dp table and return it
    return dp[i][sum] = (include || exclude);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    // Initialize a dp table with -1
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetpresent(n, k, a, 0, 0, dp);
}