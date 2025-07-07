vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    int maxi = INT_MIN;
    int range = INT_MAX;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i = 0;i<nums.size();i++) {
            pq.push({nums[i][0],{i,0}});
            maxi = max(maxi,nums[i][0]);
    }
       
        while(1) {
            auto top = pq.top();
            int ele = top.first;
            int arr = top.second.first;
            int ind = top.second.second;

            if(maxi-ele < range) {
                ans = {ele,maxi};
                range = maxi-ele;
            }

            if(ind >= nums[arr].size()-1) break;

            pq.pop();
            pq.push({nums[arr][ind+1],{arr,ind+1}});
            maxi = max(nums[arr][ind+1],maxi);
        }

        return ans;

}