int longestSubsequence(string s, int k) {
    int n = s.size();
    int bits = 0;
    int zeros = 0;
    long long curr = 0;
    int power = 0;

    // Traverse from right to left (least significant bit first)
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            bits++;
        } else {
            if (power < 63) { // prevent overflow
                long long value = 1LL << power;
                if (curr + value <= k) {
                    curr += value;
                    bits++;
                } else {
                    // cannot add more '1's, break if all further are '1'
                    // but we still count zeros
                    // don't break — just skip this '1'
                }
            }
        }
        power++;
    }

    return bits;
}