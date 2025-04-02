long long maximumTripletValue(vector<int>& nums) {
    long long ans=INT_MIN;
    for(int i=0;i<nums.size()-2;i++) {
        for(int j=i+1;j<nums.size()-1;j++) {
            for(int k=j+1;k<nums.size();k++) {
                ans= max(ans,(((long long)nums[i]-(long long)nums[j])*(long long)nums[k]));
            }
        }
    }
    
   if(ans<0) return 0;

   return ans;
}