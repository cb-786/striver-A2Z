   int minCoins(vector<int> &coins, int sum) {
       priority_queue<int> maxheap;
       int count=0;
       for(int i=0;i<coins.size();i++) {
           maxheap.push(coins[i]);
       }
       
       while(sum!=0 && !maxheap.empty()) {
           int max = maxheap.top();
           maxheap.pop();
           
          
           
           if (max <= sum) {
            count += sum / max;  // Calculate how many coins of this denomination are needed
            sum %= max;         // Update the sum with the remainder
        }
           
           
       }
       
       if(sum!=0) return -1;
     
       return count;
    }