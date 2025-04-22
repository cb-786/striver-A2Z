int atmost(int goal,vector<int> &nums) {
    int ans=0;
    int j=0;
    int i=0;
    int curr=nums[0];
    while(j<nums.size())
        {
            if(curr<=goal) {
                ans+=j-i+1;
            }

            if(curr>goal) {
                while(i<=j && curr>goal ) {
                    curr-=nums[i];
                    i++;
                }
                continue;
            }

            else {
                j++;
                if(j<nums.size())
                curr+=nums[j];
                
            }

        }
        return ans;   
 }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int total1=0;
        int total2=0;
        total1 = atmost(goal,nums);
        if(goal-1<0) return total1;
        total2 = atmost(goal-1,nums);
        return total1-total2;

    }