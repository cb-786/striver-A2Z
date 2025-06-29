int numSubseq(vector<int>& nums, int target) {
    int mod = 1e9 + 7;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    // Precompute powers of 2
    vector<int> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 2LL) % mod;
    }

    int left = 0, right = n - 1, result = 0;

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            result = (result + power[right - left]) % mod;
            left++;
        } else {
            right--;
        }
    }

    return result;
}