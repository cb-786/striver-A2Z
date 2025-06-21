int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0;
    int curr = 0;
    int start = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];

        if (curr < 0) {
            // can't reach this point from current start
            start = i + 1;
            curr = 0;
        }
    }
    
    return total < 0 ? -1 : start;
}
