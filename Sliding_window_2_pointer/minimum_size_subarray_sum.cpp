int minSubArrayLen(int target, vector<int>& nums) {
    int i=0;
    int j=0;
    int curr=0;
    int ans = INT_MAX;
    while(j<=nums.size()) {

            if(curr>=target) {
                ans = min(ans,j-i);
                cout << ans << " " << i << " " << j << endl;
                
                curr-=nums[i];
                i++;
            }

            

            else  {
                    if(j<nums.size()) {
                     curr+=nums[j];
                   
                    }
                   j++;
                    
            }

    }

    return (ans==INT_MAX) ? 0 : ans;
}