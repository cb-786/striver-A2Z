int xo(vector<int> &nums) {
    if(nums.empty()) return 0;

    

                int tmp = 0;
                int mask =0;
                
                while(tmp<nums.size()) {
                    mask=(nums[tmp]^mask);
                    cout << mask << endl;
                    tmp++; 
                }
                return mask;
             
        
    }

void rec(vector<int> &nums,int i,int &ans,vector<int> &sub) {
        if(i>=nums.size()) {
            ans+=xo(sub);
            return ;
        }

        sub.push_back(nums[i]);
        rec(nums,i+1,ans,sub);
        sub.pop_back();
        rec(nums,i+1,ans,sub);

        return ;


}



int subsetXORSum(vector<int>& nums) {
        vector<int> sub;
        int ans=0;
        rec(nums,0,ans,sub);
        return ans;
}