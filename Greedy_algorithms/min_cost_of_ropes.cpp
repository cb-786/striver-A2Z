int minCost(vector<int>& arr) {
      priority_queue<int, vector<int>, greater<int>> minheap;
      
      for(int i=0;i<arr.size();i++) {
          minheap.push(arr[i]);
      }
      int ans=0;
      while(minheap.size()>1) {
          int a = minheap.top();
          minheap.pop();
          int b= minheap.top();
          minheap.pop();
          int c = a+b;
          ans+=c;
          minheap.push(c);
      }
      
      return ans;
      
      
    }