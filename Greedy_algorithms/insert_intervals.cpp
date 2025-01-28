vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0];
    int e = newInterval[1];
    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++) {
        // Case 1: Current interval ends before newInterval starts
        if (intervals[i][1] < s) {
            ans.push_back(intervals[i]);
        }
        // Case 2: Current interval starts after newInterval ends
        else if (intervals[i][0] > e) {
            ans.push_back({s, e});  // Add the merged newInterval
            ans.insert(ans.end(), intervals.begin() + i, intervals.end()); // Add all remaining intervals
            return ans;  // Since all intervals are added, return the result
        }
        // Case 3: Overlapping intervals, merge them
        else {
            s = min(s, intervals[i][0]);
            e = max(e, intervals[i][1]);
        }
    }

    // Add the last interval
    ans.push_back({s, e});

    return ans;
    }