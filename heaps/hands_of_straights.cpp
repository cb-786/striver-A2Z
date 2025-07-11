bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;

    priority_queue<int> pq;
    unordered_map<int, int> freq;
    vector<int> store;
    int tmp = groupSize;

    for (const auto& ele : hand) {
        pq.push(ele);
        freq[ele]++;
    }

    while (!pq.empty()) {
        // Skip used-up elements
        while (!pq.empty() && freq[pq.top()] == 0) {
            pq.pop();
        }

        if (pq.empty()) break;

        int prev = pq.top();
        pq.pop();
        freq[prev]--;
        tmp = groupSize - 1;

        while (tmp != 0) {
            prev--;

            if (freq[prev] == 0) return false;

            freq[prev]--;
            tmp--;
        }
    }

    return true;
}