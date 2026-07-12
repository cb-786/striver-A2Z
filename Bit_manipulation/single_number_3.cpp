  vector<int> singleNumber(vector<int>& nums) {
        int res=0;
        for(const auto &ele:nums) {
            res =res^ele;
        }
        long long firstrightbit=(((long long)res)&((long long)res-1))^res;
        int a = 0;
        int b=0;
        for(const auto &ele:nums) {
            if(ele&firstrightbit) {
                a=a^ele;
            }
            else {
                b=b^ele;
            }
        }
        return {a,b};
    }