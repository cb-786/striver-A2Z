 int jump(vector<int>& nums) {
        int maxind=0;
        int count=0;
       int currend = 0;

       if(nums.size() == 1) {
        return 0;
       }
       
        for(int i=0;i<=maxind;i++) {
          
           maxind = max(maxind,i+nums[i]);
            
            if(currend == i) {
                count++;
                currend = maxind;

                if(maxind>=nums.size()-1) return count;
                
            }
             
            
        }
        return count;
    }