int countPrimes(int n) {
        if(n<2) return 0;
        int ans=0;
        vector<int> sieve(n,1);
        sieve[0]=0;
        sieve[1]=0;
        for(int p=2;p*p<n;p++) {
            if(sieve[p]) {
                for(int i=p*p;i<n;i+=p) {
                    sieve[i]=0;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(sieve[i]) ans++;
        }
        return ans;
    }