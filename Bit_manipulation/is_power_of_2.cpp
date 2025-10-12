bool isPowerOfTwo(long long n) {
        if(n==0 || n<0) return 0;

       while(n>1) {
        if(n%2==1) return false;
        n=n/2;
       }
       return true;
    }