vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(const auto&ele : spells) {
            int s = 0;
            int e = potions.size()-1;
            int mid = (s+e)/2;
            int pot = potions.size();

            while(s<=e) {
                if((long long)potions[mid]*(long long)ele >= success) {
                    pot = mid;
                    e=mid-1;
                }

                if((long long)potions[mid]*(long long)ele < success) {
                        s=mid+1;
                }
                                mid = (s+e)/2;

            }
            
                ans.push_back(potions.size()-pot);

        }
        return ans;
    }