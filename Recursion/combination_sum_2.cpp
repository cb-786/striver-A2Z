class Solution {
public:

    void sumofsubsetDP(const vector<int>& candidates, int target, int i, vector<int>& sub, vector<vector<int>>& ans) {
    // Base case: if target is 0, store the subset
    if (target == 0) {
        ans.push_back(sub);
        return;
    }

    // If index is out of bounds or target becomes negative
    if (i >= candidates.size() || target < 0) {
        return;
    }

    // Iterate through candidates starting from index i
    for (int j = i; j < candidates.size(); ++j) {
        // Skip duplicates
        if (j > i && candidates[j] == candidates[j - 1]) {
            continue;
        }

        // Include the current element
        sub.push_back(candidates[j]);

        // Recurse for the remaining target
        sumofsubsetDP(candidates, target - candidates[j], j + 1, sub, ans);

        // Backtrack by removing the last element
        sub.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sub;

    // Sort the candidates to handle duplicates and maintain order
    sort(candidates.begin(), candidates.end());

    // Start the recursion
    sumofsubsetDP(candidates, target, 0, sub, ans);

    return ans;
}
};