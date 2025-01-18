 int ro(vector<int> &nums,int i) {
        if(i>=nums.size()) {
            return 0;
        }

       
         
                
               int r1 = nums[i] + ro(nums,i+2,ans);
          
               int f1 = 0 + ro(nums,i+1,ans);
               
            return max(r1,f1);
              
             

    }
    int rob(vector<int>& nums) {
       
       return ro(nums,0,ans);
       
    }