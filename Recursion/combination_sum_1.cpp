class Solution {
public:


  


   void combination(vector<vector<int>>& ans, vector<int> &sub, const vector<int>& candidates, int &target, int sum, int i) {
    if (sum == target) {
        // Store the valid combination
        sort(sub.begin(),sub.end());
        ans.push_back(sub);
        return;
    }

    if (sum > target || i >= candidates.size()) {
        return; // Invalid combination or index out of range
    }

    // Include the current element and stay on the same index (allowing reuse of the same element)
    sub.push_back(candidates[i]);
    combination(ans, sub, candidates, target, sum + candidates[i], i);

    // Exclude the current element and move to the next index
    sub.pop_back(); // Backtrack to explore other options
    combination(ans, sub, candidates, target, sum, i + 1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sub;

    // Sort the candidates to maintain consistency in subsets
    sort(candidates.begin(), candidates.end());

    // Start the recursion
    combination(ans, sub, candidates, target, 0, 0);

    // Deduplicate combinations using a set
    set<vector<int>> uniqueCombinations(ans.begin(), ans.end());
    ans.assign(uniqueCombinations.begin(), uniqueCombinations.end());

    return ans;
}
};