static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // Sort based on end times
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort intervals by their end times
    sort(intervals.begin(), intervals.end(), comp);

    int count = 1;    // Count of overlapping intervals
    int last = intervals[0][1]; // End time of the last included interval

    for (int i = 1; i < intervals.size(); i++) {
        // If there is an overlap
        if (intervals[i][0] >= last) {
            count++;
            last = intervals[i][1]; // Remove this interval
        } 
    }

    return intervals.size()-count; // Number of intervals to remove
}
