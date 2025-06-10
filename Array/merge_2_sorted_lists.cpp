void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=0;i<nums2.size();i++) {
        int j=0;
        while(j<nums1.size() && nums1[j]<=nums2[i]) {
           
            
            j++;
        }
        if(j==nums1.size()) {
            j=m;
        }
        
        int tmp=m;
        while(tmp!=j) {
            swap(nums1[tmp],nums1[tmp-1]);
            tmp--;
        }
        nums1[j] = nums2[i];
        m++;
    }