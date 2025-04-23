int countLargestGroup(int n) {
    unordered_map<int,int> freq;
    int ans=0;
    int maxi = INT_MIN;
    for(int i=1;i<=n;i++) {
        int sum=0;
        int tmp=i;
        while(tmp!=0) {
            sum+=tmp%10;
            tmp=tmp/10;
        }
        freq[sum]++;
        maxi = max(maxi,freq[sum]);
    }

    for(auto [u,v] : freq) {
            if(v==maxi) {
                ans++;
            }
    }

    return ans;
}