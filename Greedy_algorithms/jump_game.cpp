  bool canJump(vector<int>& nums) {
        int maxind=0;
        int i=0;
        while(i<=maxind) {
            if(maxind>=nums.size()-1) {
                return true;
            }

            maxind =max(maxind,i+nums[i]);
            i++;
        }

        return false;
    }