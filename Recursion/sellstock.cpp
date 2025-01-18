


    // Recursive helper function to find maximum profit
    int pro(vector<int>& prices, int i, int minPrice) {
        // Base case: If we've reached the end, return 0 (no more profit can be made)
        if (i >= prices.size()) return 0;

        // Calculate the profit if we sell at the current price
        int currProfit = prices[i] - minPrice;

        // Update the minimum price seen so far
        minPrice = min(minPrice, prices[i]);

        // Recur for the next day
        int futureProfit = pro(prices, i + 1, minPrice);

        // Return the maximum profit between selling today or in the future
        return max(currProfit, futureProfit);
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // Edge case: empty prices array
        return pro(prices, 0, INT_MAX); // Start with the first day and a large minimum price
    }
