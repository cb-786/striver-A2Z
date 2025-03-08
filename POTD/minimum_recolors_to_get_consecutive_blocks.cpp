int minimumRecolors(string blocks, int k) {
    int l=0;
    int r=k-1;
    int ans=INT_MAX;
    int cnt=0;
    while(r<blocks.size()) {
        cnt=0;
        int i=l;
        while(i<=r) {
            if(blocks[i]=='W') {
                cnt+=1;
            }
            i++;
        }
        ans=min(ans,cnt);
       l++;
       r++;
    }
return ans;
}