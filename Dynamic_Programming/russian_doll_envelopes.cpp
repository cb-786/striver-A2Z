int bs(vector<vector<int>>& num) {
    int n = num.size();
    vector<int> ans; // Stores only heights to perform LIS

    for (int i = 0; i < n; i++) {
        int height = num[i][1]; 
        auto it = lower_bound(ans.begin(), ans.end(), height);
        int index = distance(ans.begin(), it);

        if (it == ans.end()) {
            ans.push_back(height);
        } else {
            ans[index] = height; // Replacing to maintain LIS property
        }
    }

    return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Sort by width in ascending, and by height in descending for equal widths
    sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    return bs(envelopes);
}