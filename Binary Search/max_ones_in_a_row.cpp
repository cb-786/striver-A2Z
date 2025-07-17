vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> ans = {0, 0};  // Start with default answer
    for (int i = 0; i < mat.size(); i++) {
       
        sort(mat[i].begin(),mat[i].end());
        int s = 0;
        int e = mat[i].size() - 1;  // Use mat[i], not mat[0]
        int answer = mat[i].size(); // Initialize to size, not e+1
        while (s <= e) {
            int mid = s + (e - s) / 2;  // Fix mid calculation
            if (mat[i][mid] == 1) {
                answer = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        int ones = mat[i].size() - answer;
        if (ones > ans[1]) {
            ans = {i, ones};
        }
    }
    return ans;
}