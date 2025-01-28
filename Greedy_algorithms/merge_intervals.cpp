vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

    // Step 1: Sort the intervals by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Start with the first interval
    ans.push_back(intervals[0]);

    // Step 3: Traverse through the intervals
    for (int i = 1; i < intervals.size(); i++) {
        // Get the last interval in `ans`
        vector<int>& lastInterval = ans.back();

        // Case 1: No overlap, add the current interval
        if (intervals[i][0] > lastInterval[1]) {
            ans.push_back(intervals[i]);
        }
        // Case 2: Overlap, merge intervals
        else {
            lastInterval[1] = max(lastInterval[1], intervals[i][1]);
        }
    }

    return ans;
    }