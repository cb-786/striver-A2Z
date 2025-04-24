int countCompleteSubarrays(vector<int>& nums) {
    unordered_map<int,int> freq;
    int goal = 0;
    int ans=0;
    for(int i=0;i<nums.size();i++) {
            if(freq[nums[i]]==0) goal++;
            freq[nums[i]]++;
    }
    unordered_map<int,int> tmp;
    int j=0;
    int tgoal=0;
    for(int i=0;i<nums.size();i++) {
        if(i>0) {
             tmp[nums[i-1]]--;
            if(tmp[nums[i-1]] == 0) tgoal --;
        }

        while(j<nums.size() && tgoal < goal) {
            if(tmp[nums[j]]==0) tgoal++;
            tmp[nums[j]]++;
            j++;
        }

        if(goal==tgoal) {
            ans+=nums.size()-j+1;
        }


    }

    return ans;
}