bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++) {
              bool e1 = (nums[i]%2==0);
              bool e2 = (nums[i+1]%2==0);

              if(!((e1 && !e2) || (!e1&&e2))) {
                   return false;
              }
        }
        return true;
    }