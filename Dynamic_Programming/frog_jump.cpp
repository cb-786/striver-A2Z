 int minCost(vector<int>& height) {
        
      
       int prev=0;
        int prev2=0;
       
        for(int i=1;i<height.size();i++) {
        int l = prev + abs(height[i]-height[i-1]);
        int r = INT_MAX;
        if(i>1) 
         r = prev2 + abs(height[i]-height[i-2]);
        
        int curri =  min(l,r);
        prev2=prev;
        prev=curri;
        
        }
        
      
        return prev;
      
    }