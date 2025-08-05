int totalFruit(vector<int>& fruits) {
        int basket[2] = {-1, -1};
        int i = 0;
        int j = 0;
        int ans = 0;  // Changed from INT_MIN to 0
        
        while(j < fruits.size()) {
            // If first basket is empty
            if(basket[0] == -1) {
                basket[0] = fruits[j];
                j++;
                ans = max(ans, j - i);
                continue;
            }
            
            // If second basket is empty
            if(basket[1] == -1) {
                if(basket[0] != fruits[j]) {
                    basket[1] = fruits[j];
                }
                j++;
                ans = max(ans, j - i);
                continue;
            }
            
            // If current fruit matches either basket
            if(basket[0] == fruits[j] || basket[1] == fruits[j]) {
                j++;
                ans = max(ans, j - i);
                continue;
            }
            
            // Need to slide the window - move left pointer
            else {
                // Move i forward until we have only one type of fruit
                int lastFruit = fruits[j-1];
                i = j - 1;
                while(i > 0 && fruits[i-1] == lastFruit) {
                    i--;
                }
                
                // Update baskets
                basket[0] = lastFruit;
                basket[1] = fruits[j];
                j++;
                ans = max(ans, j - i);
            }
        }
        
        return ans;
    }