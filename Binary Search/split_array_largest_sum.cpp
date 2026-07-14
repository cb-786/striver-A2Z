bool candiv(vector<int> &arr,int k,long long maxpayne) {
        int currchild=1;
        long long csum=0;
        for(const auto &ele:arr) {
            if(csum+ele>maxpayne) {
                currchild++;
                csum=0;
            }
            csum+=ele;
        }
        return (k>=currchild) ? 1:0;
    }



    int splitArray(vector<int>& arr, int k) {
        if(k>arr.size()) return -1;
        
        
        long long s=INT_MIN;
        long long e =0;
        for(const auto &ele:arr) {
            s=max(s,(long long)ele);
            e+=ele;
        }
        long long ans = -1;
        while(s<=e) {
            long long mid = s + (e-s)/2;
            if(candiv(arr,k,mid)) {
                ans=mid;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
    }