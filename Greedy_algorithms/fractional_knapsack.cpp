 double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<double> valwtRatio;
    int n = val.size();

    // Compute value-to-weight ratios
    for (int i = 0; i < n; i++) {
        double ratio = (double)val[i] / wt[i];
        valwtRatio.push_back(ratio);
    }

    // Build max heap using a priority queue
    priority_queue<pair<double, pair<int, int>>> maxi;
    for (int i = 0; i < n; i++) {
        maxi.push({valwtRatio[i], {val[i], wt[i]}});
    }

    // Initialize total value
    double totalVal = 0;

    // Process the max heap
    while (capacity != 0 && !maxi.empty()) {
        auto front = maxi.top();
        double ratio = front.first;
        int value = front.second.first;
        int weight = front.second.second;

        maxi.pop();

        if (capacity >= weight) {
            // Take the full item
            totalVal += value;
            capacity -= weight;
        } else {
            // Take a fraction of the item
            double valueToInclude = ratio * capacity;
            totalVal += valueToInclude;
            capacity = 0;
        }
    }

    return totalVal;
}