int ans = INT_MIN;
    void maximi(int n, int x, int y, int z,int cut,int curr) {
        if(cut>=n) {
            if(cut==n) {
                n=0;
                curr++;
            }
            ans = max(ans,curr);
            return ;
        }
       
        
        maximi(n-cut,x,y,z,x,curr+1);
        maximi(n-cut,x,y,z,y,curr+1);
        maximi(n-cut,x,y,z,z,curr+1);
        
        
        return ;
        
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        maximi(n,x,y,z,0,-1);
        return ans;
    }