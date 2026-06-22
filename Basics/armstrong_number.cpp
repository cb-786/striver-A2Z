bool armstrongNumber(int n) {
        // code here
        int tmp = n;
        int ans =0;
        while(tmp!=0) {
            ans+=pow((tmp%10),3);
            tmp=tmp/10;
        }
        return(ans==n);
    }