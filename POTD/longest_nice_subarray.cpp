int longestNiceSubarray(vector<int>& nums) {
    int l = 0;
    int r = 0;
    int ans = 1; // Initialize to 1 since a subarray of length 1 is always nice
    int mask = 0; // Use a bitmask to track bits

    while (r < nums.size()) {
        // Check if current number can be added to nice subarray
        while ((mask & nums[r]) != 0) {
            // Remove leftmost number from our mask
            mask ^= nums[l];
            l++;
        }
        
        // Add current number to our mask
        mask |= nums[r];
        
        // Update answer
        ans = max(ans, r - l + 1);
        r++;
    }
    
    return ans;
}
