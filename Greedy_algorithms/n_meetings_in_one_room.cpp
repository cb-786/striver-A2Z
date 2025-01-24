 int minMeetings(vector<int>& st, vector<int>& end) {
    int n = st.size();
    if (n == 0) return 0;

    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++) {
        time.push_back({st[i], end[i]});
    }

    // Use a lambda comparator
    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int count = 1;
    int prevEnd = time[0].second;

    for (int i = 1; i < n; i++) {
        int currStart = time[i].first;

        if (currStart > prevEnd) {
            count++;
            prevEnd = time[i].second;
        }
    }

    return count;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    return minMeetings(start, end);
}